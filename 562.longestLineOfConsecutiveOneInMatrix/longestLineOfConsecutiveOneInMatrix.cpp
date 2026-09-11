#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.size() == 0 || M[0].size() == 0)
            return 0;
        int m = M.size(), n = M[0].size();
        int res = 0;
        vector<vector<int> > dp_h = M, dp_v = dp_h, dp_d = dp_h, dp_ad = dp_h;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (M[i][j] == 0)
                    continue;
                if (j > 0)
                    dp_h[i][j] += dp_h[i][j - 1];
                if (i > 0)
                    dp_v[i][j] += dp_v[i - 1][j];
                if (i > 0 && j > 0)
                    dp_d[i][j] += dp_d[i - 1][j - 1];
                if (j + 1 < n && i > 0)
                    dp_ad[i][j] += dp_ad[i - 1][j + 1];
                res = max (res, max (dp_h[i][j], dp_v[i][j]));
                res = max (res, max (dp_d[i][j], dp_ad[i][j]));
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
