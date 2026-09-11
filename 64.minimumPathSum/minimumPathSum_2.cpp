// clang++ minimumPathSum_2.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        vector<int> dp(n + 1, INT_MAX);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1)
                    dp[j] = grid[0][0];
                else
                    dp[j] = min (dp[j - 1], dp[j]) + grid[i - 1][j - 1];
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    int a1[4] = {0,0,0,0};
    int a2[4] = {0,1,0,1};
    int a3[4] = {1,0,1,0};
    int a4[4] = {0,0,0,1};
    vector<int> vec1(a1, a1+4);
    vector<int> vec2(a2, a2+4);
    vector<int> vec3(a3, a3+4);
    vector<int> vec4(a4, a4+4);
    vector<vector<int> > matrix;
    matrix.push_back(vec1);
    matrix.push_back(vec2);
    matrix.push_back(vec3);
    matrix.push_back(vec4);
    cout << s.minPathSum(matrix) << endl;
    return 0;
}
