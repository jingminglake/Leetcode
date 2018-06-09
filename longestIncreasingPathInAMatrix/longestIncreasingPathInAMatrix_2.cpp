#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 0;
        if (matrix.size() == 0)
            return res;
        vector<vector<int> > dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        vector<pair<int, int> > dirs = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        vector<vector<bool> > visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                visited[i][j] = true;
                res = max (res, dfs (i, j, matrix, dirs, dp, visited));
                visited[i][j] = false;
            }
        }
        return res;
    }
    int dfs (int start_i, int start_j, vector<vector<int> >& matrix, vector<pair<int, int> >& dirs, vector<vector<int> >& dp, vector<vector<bool> >& visited) {
        if (dp[start_i][start_j] != -1)
            return dp[start_i][start_j];
        int depth = 1;
        for (auto& dir : dirs) {
            int next_i = start_i + dir.first;
            int next_j = start_j + dir.second;
            if (next_i < 0 || next_i >= matrix.size() || next_j < 0 || next_j >= matrix[0].size() || matrix[next_i][next_j] <= matrix[start_i][start_j] || visited[next_i][next_j])
                continue;
            visited[next_i][next_j] = true;
            depth = max (depth, dfs(next_i, next_j, matrix, dirs, dp, visited) + 1);
            visited[next_i][next_j] = false;
        }
        return dp[start_i][start_j] = depth;
    }
};

int main() {
    Solution s;
    vector<vector<int>> nums = {{9,9,4},{6,6,8},{2,1,1}}; 
    cout << s.longestIncreasingPath(nums) << endl;
    return 0;
}
