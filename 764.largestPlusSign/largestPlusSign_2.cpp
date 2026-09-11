#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int> > grid(N, vector<int>(N, 1));
        for (int i = 0; i < mines.size(); i++) {
            grid[mines[i][0]][mines[i][1]] = 0;
        }
        vector<vector<int> > dp_left = grid, dp_right = dp_left, dp_up = dp_left, dp_down = dp_left;
        for (int i = 1; i < N; i++) {
            for (int j = 1; j < N; j++) {
                if (grid[i][j] == 1) {
                    dp_left[i][j] = dp_left[i][j - 1] + 1;
                    dp_up[i][j] = dp_up[i - 1][j] + 1;
                }
                else {
                    dp_left[i][j] = 0;
                    dp_up[i][j] = 0;
                }
            }
        }
        for (int i = N - 2; i >= 0; i--) {
            for (int j = N - 2; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    dp_right[i][j] = dp_right[i][j + 1] + 1;
                    dp_down[i][j] = dp_down[i + 1][j] + 1;
                }
                else {
                    dp_right[i][j] = 0;
                    dp_down[i][j] = 0;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0, l = 0; j < N; j++) {
                int temp1 = min (dp_left[i][j], dp_right[i][j]);
                int temp2 = min (dp_up[i][j], dp_down[i][j]); 
                res = max (res, min(temp1, temp2));
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > mines = {{4,2}};
    cout << s.orderOfLargestPlusSign(5, mines);
    cout << endl;
    return 0;
}
