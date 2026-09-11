#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, INT_MAX));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1)
                    dp[i][j] = dungeon[i][j] > 0 ? 1 : -dungeon[i][j] + 1;
                else {
                    int initial = -dungeon[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
                    dp[i][j] = initial <= 0 ? 1 : initial;
                }
            }
        }
        return dp[0][0];
    }
};

int main()
{
    Solution s;
    vector<vector<int> > dungeon = { {-2,-3, 3},
                                     {-5,-10,1},
                                     {10,30,-5}};
    cout << s.calculateMinimumHP(dungeon) << endl;
    return 0;
}
