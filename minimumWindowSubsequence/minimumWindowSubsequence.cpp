#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        int s_len = S.length(), t_len = T.length();
        vector<vector<int> > dp(s_len + 1, vector<int>(t_len + 1, INT_MAX));
        for (int i = 0; i <= s_len; i++)
            dp[i][0] = i;
        for (int i = 1; i <= s_len; i++) {
            for (int j = 1; j <= t_len; j++) {
                if (S[i - 1] == T[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        int start_index = -1, min_len = s_len + 1;
        for (int i = 1; i <= s_len; i++) {
            if (dp[i][t_len] != INT_MAX) {
                if (i - dp[i][t_len] < min_len) {
                    start_index = dp[i][t_len];
                    min_len = i - dp[i][t_len];
                }
            }
        }
        return start_index == -1 ? "" : S.substr(start_index, min_len);
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
