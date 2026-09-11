#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> top_bottom(n, INT_MIN);
        vector<int> left_right(m, INT_MIN);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                top_bottom[j] = max (top_bottom[j], grid[i][j]);
                left_right[i] = max (left_right[i], grid[i][j]);
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res += min (top_bottom[j], left_right[i]) - grid[i][j];
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int> > grid = {{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};
    cout << s.maxIncreaseKeepingSkyline(grid) << endl;
    return 0;
}
