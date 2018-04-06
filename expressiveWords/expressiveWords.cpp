#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int res = 0;
        if (S.length() == 0 || words.size() == 0)
            return res;
        string compS = compress(S);
        //cout << compressS << endl;
        for (string& word : words) {
            string compW = compress(word);
            if (compS.length() != compW.length())
                continue;
            bool couldExpend = true;
            for (int i = 0; i < compS.length(); i += 2) {
                if (compS[i] != compW[i] || compS[i + 1] < compW[i + 1]) {
                    couldExpend = false;
                    break;
                }
                if (compS[i + 1] - '0' < 3 && compS[i + 1] != compW[i + 1]) {
                    couldExpend = false;
                    break;
                }
            }
            if (couldExpend)
                res++;
        }
        return res;
    }
    string compress(string s) {
        string res;
        if (s.length() == 0)
            return res;
        int count = 1;
        res = s[0];
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                res += to_string(count) + s[i];
                count = 1;
            }
        }
        res += to_string(count);
        return res;
    }
};

int main() {
  string S = "heeellooo";
  vector<string> words = {"hello", "hi", "helo"};
  Solution s;
  cout << s.expressiveWords(S, words) << endl;
  return 0;
}
