#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int res = 0;
        int m = M.size();
        if (m == 0)
            return res;
        int n = M[0].size();
        vector<vector<vector<int> > > dp(m, vector<vector<int> >(n, vector<int>(4, 0)));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (M[i][j] == 0)
                    continue;
                for (int k = 0; k < 4; k++)
                    dp[i][j][k] = 1;
                if (j > 0)
                    dp[i][j][0] += dp[i][j - 1][0];
                if (i > 0)
                    dp[i][j][1] += dp[i - 1][j][1];
                if (i > 0 && j > 0)
                    dp[i][j][2] += dp[i - 1][j - 1][2];
                if (j + 1 < n && i > 0)
                    dp[i][j][3] += dp[i - 1][j + 1][3];
                res = max (res, max (dp[i][j][0], dp[i][j][1]));
                res = max (res, max (dp[i][j][2], dp[i][j][3]));
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int> > M = {{0,1,1,0},
                              {0,1,1,0},
                              {0,0,0,1}};
    cout << s.longestLine(M) << endl;
    return 0;
}
