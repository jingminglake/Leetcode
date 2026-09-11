// clang++ uniquePathsII.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0)
            return 0;
        int n = obstacleGrid[0].size();
        if (n == 0 || obstacleGrid[0][0] == 1)
            return 0;
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1)
                    dp[i][j] = 1;
                else if (obstacleGrid[i - 1][j - 1] == 0)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution s;
    vector<vector<int> > grid = {{0,0,0}, {0,1,0}, {0,0,0}};
    cout << s.uniquePathsWithObstacles(grid) << endl;;
    return 0;
}
