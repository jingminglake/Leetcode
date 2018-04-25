#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int res = 0;
        if (grid.size() == 0)
            return res;
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int> > > dp(m, vector<vector<int> >(n, vector<int>(4, 0)) );
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int up = (i == 0 || grid[i][j] == 'W') ? 0 : dp[i - 1][j][0];
                int left = (j == 0 || grid[i][j] == 'W') ? 0 : dp[i][j - 1][1];
                dp[i][j][0] = grid[i][j] == 'E' ? up + 1: up;
                dp[i][j][1] = grid[i][j] == 'E' ?left + 1 : left;
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int down = (i == m - 1 || grid[i][j] == 'W') ? 0 : dp[i + 1][j][2];
                int right = (j == n - 1 || grid[i][j] == 'W') ? 0 : dp[i][j + 1][3];
                dp[i][j][2] = grid[i][j] == 'E' ? down + 1: down;
                dp[i][j][3] = grid[i][j] == 'E' ? right + 1 : right;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') {
                    res = max (res, dp[i][j][0] + dp[i][j][1] + dp[i][j][2] + dp[i][j][3]);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<char>> grid = { {'0', 'E', '0', '0'},
                                  {'E', '0', 'W', 'E'},
                                  {'0', 'E', '0', '0'}};
    cout << s.maxKilledEnemies(grid) << endl;
    return 0;
}
