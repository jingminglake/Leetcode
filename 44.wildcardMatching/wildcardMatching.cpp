#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.length() == 0 && p.length() == 0)
            return true;
        vector<vector<bool> > dp(s.length() + 1, vector<bool>(p.length() + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= p.length(); i++) {
            if (p[i - 1] == '*') {
                dp[0][i] = dp[0][i - 1];
            }
        }
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 1; j <= p.length(); j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j - 1] || dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }
        return dp[s.length()][p.length()];
    }
};

int main()
{
  Solution s;
  cout << s.isMatch("aa", "a") << endl;
  cout << s.isMatch("aa", "aa") << endl;
  cout << s.isMatch("aaa", "a") << endl;
  cout << s.isMatch("aa", "a*") << endl;
  cout << s.isMatch("aa", "?*") << endl;
  cout << s.isMatch("ab", "?*") << endl;
  cout << s.isMatch("aab", "c*a*b") << endl;
  return 0;
}
