#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        int res = 0, rowE;
        vector<int> colE(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0 || grid[i][j - 1] == 'W') {
                    rowE = 0;
                    for (int k = j; k < n && grid[i][k] != 'W'; k++)
                        rowE += grid[i][k] == 'E' ? 1 : 0;
                }
                if (i == 0 || grid[i - 1][j] == 'W') {
                    colE[j] = 0;
                    for (int k = i; k < m && grid[k][j] != 'W'; k++)
                        colE[j] += grid[k][j] == 'E' ? 1 : 0;
                }
                if (grid[i][j] == '0')
                    res = max (res, rowE + colE[j]);
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
