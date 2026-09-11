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
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1)
                    dp[j] = 1;
                else if (obstacleGrid[i - 1][j - 1] == 0)
                    dp[j] += dp[j - 1];
                else
                    dp[j] = 0;
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    vector<vector<int> > grid = {{0,0,0}, {0,1,0}, {0,0,0}};
    cout << s.uniquePathsWithObstacles(grid) << endl;;
    return 0;
}
