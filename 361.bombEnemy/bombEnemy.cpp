#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int res = 0;
        if (grid.size() == 0 || grid[0].size() == 0)
            return res;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > dp_left(m, vector<int>(n, 0)), dp_right = dp_left, dp_up = dp_left, dp_down = dp_left;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int left = (j == 0 || grid[i][j] == 'W') ? 0 : dp_left[i][j - 1];
                int up = (i == 0 || grid[i][j] == 'W') ? 0 : dp_up[i - 1][j];
                dp_left[i][j] = grid[i][j] == 'E' ? left + 1 : left;
                dp_up[i][j] = grid[i][j] == 'E' ? up + 1 : up;
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int right = (j == n - 1 || grid[i][j] == 'W') ? 0 : dp_right[i][j + 1];
                int down = (i == m - 1 || grid[i][j] == 'W') ? 0 : dp_down[i + 1][j];
                dp_right[i][j] = grid[i][j] == 'E' ? right + 1 : right;
                dp_down[i][j] = grid[i][j] == 'E' ? down + 1 : down;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') {
                    res = max (res, dp_left[i][j] + dp_up[i][j] + dp_right[i][j] + dp_down[i][j]);
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
