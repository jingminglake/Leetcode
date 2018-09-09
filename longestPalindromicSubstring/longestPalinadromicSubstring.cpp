#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len_s = s.length();
        vector<vector<bool> > dp(len_s, vector<bool>(len_s, false));
        int max_len = 0, start_index = 0;
        for (int i = len_s - 1; i >= 0; i--) {
            for (int j = i; j < len_s; j++) {
                if (i == j)
                    dp[i][j] = true;
                else if (j - i == 1)
                    dp[i][j] = (s[i] == s[j]);
                else
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                if (dp[i][j] && j - i + 1 > max_len) {
                    max_len = j - i + 1;
                    start_index = i;
                }
            }
        }
        return s.substr(start_index, max_len);
    }
};


int main()
{
    Solution s;
    string ss = "cbbd";
    cout << s.longestPalindrome(ss) << endl;
    return 0;
}
