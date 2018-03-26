#include <iostream>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res;
        if (S.length() == 0)
            return res;
        int count = 0;
        string temp;
        int i = S.length() - 1;
        for (i; i >= 0; i--) {
            if (S[i] == '-')
                continue;
            if (++count <= K) {
                if (isalpha(S[i]))
                    temp += toupper(S[i]);
                else
                    temp += S[i];
            }
            if (count == K) {
                res += temp + '-';
                count = 0;
                temp = "";
            }
        }
        if (count != 0)
            res += temp;
        else if (!res.empty())
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
  Solution s;
  string S = "2-5g-3-J";
  cout << s.licenseKeyFormatting(S, 2) << endl;
  return 0;
}
