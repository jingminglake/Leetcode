class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0)
            return 0;
        int n = matrix[0].size();
        int res = 0;
        vector<vector<int> > dp = matrix;
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] += dp[i][j - 1];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                unordered_map<int, int> counter;
                counter[0] = 1;
                int preSum = 0;
                for (int k = 0; k < m; k++) {
                    preSum += dp[k][j] - (i > 0 ? dp[k][i - 1] : 0);
                    res += counter[preSum - target];
                    counter[preSum]++;
                }
            }
        }
        return res;
    }
};
