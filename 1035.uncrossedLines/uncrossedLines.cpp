class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int size_a = A.size(), size_b = B.size();
        if (size_a == 0 || size_b == 0)
            return 0;
        vector<vector<int> > dp(size_a + 1, vector<int>(size_b + 1, 0));
        for (int i = 1; i <= size_a; i++) {
            for (int j = 1; j <= size_b; j++) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);                
                }
            }
        } //for
        return dp[size_a][size_b];
    }
};
