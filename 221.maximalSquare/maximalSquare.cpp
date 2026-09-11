// clang++ maximalSquare.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        int res = 0;
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0] - '0';
            res = max(res, dp[i][0]);
        }   
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j] - '0';
            res = max(res, dp[0][j]);
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min (dp[i - 1][j - 1], min (dp[i][j - 1], dp[i - 1][j]) ) + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res * res;
    }
};

int main()
{
    Solution s;
    vector<vector<char> > matrix = {{'1','0','1','0','0'},
                                    {'1','0','1','1','1'},
                                    {'1','1','1','1','1'},
                                    {'1','0','0','1','0'}};
    cout << s.maximalSquare(matrix) << endl;
    return 0;
}
