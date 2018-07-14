// O(m^2 * n) TLE
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        string res = "";
        int min_len = S.length();
        for (int left = 0; left <= (int)S.length() - (int)T.length(); left++) {
            if (S[left] != T[0])
                continue;
            string W = S.substr(left, min_len);
            int len = isSubsequence(W, T);
            if (len != -1 && len < min_len) {
                res = S.substr(left, len);
                min_len = len;
            }
        }
        return res;
    }
    int isSubsequence(string& w, string& t) {
        int p_w = 0, p_t = 0;
        while (p_w < w.length() && p_t < t.length()) {
            if (w[p_w] == t[p_t])
                p_t++;
            p_w++;
        }
        return p_t == t.length() ? p_w : -1;
    }
};

int main()
{
  Solution s;
  string S = "abcdebdde";
  string T = "bde";
  cout << s.minWindow(S, T) << endl;
  return 0;
}
