#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return 0;
        vector<vector<int> > dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        int res = 1;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                res = max (res, dfs (matrix, i, j, dp));
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int> >& dp) {
        if (dp[i][j] != -1)
            return dp[i][j];
        vector<pair<int, int> > dirs = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, 1), make_pair(0, -1)};
        for (auto& dir : dirs) {
            int m = i + dir.first;
            int n = j + dir.second;
            if (m < 0 || m >= matrix.size() || n < 0 || n >= matrix[0].size() || matrix[m][n] <= matrix[i][j])
                continue;
            dp[i][j] = max (dp[i][j], dfs (matrix, m, n, dp) + 1);
        }
        dp[i][j] = max (dp[i][j] , 1);
        return dp[i][j];
    }
};

int main() {
  Solution s;
  vector<vector<int>> nums = {{9,9,4},{6,6,8},{2,1,1}}; 
  cout << s.longestIncreasingPath(nums) << endl;
  return 0;
}
