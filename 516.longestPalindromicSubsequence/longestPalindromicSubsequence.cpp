// clang++ longestPalindromicSubsequence.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len_s = s.length();
        vector<vector<int> > dp(len_s, vector<int>(len_s, 0));
        for (int i = len_s - 1; i >= 0; i--) {
            for (int j = i; j < len_s; j++) {
                if (i == j)
                    dp[i][j] = 1;
                else if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2; 
                else  
                    dp[i][j] = max (dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][len_s - 1];
    }
};

int main()
{
    Solution s;
    string ss = "bbbab";
    cout << s.longestPalindromeSubseq(ss) << endl;
    return 0;
}
