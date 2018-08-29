#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<vector<bool> > rows(n, vector<bool>(n, false)), cols = rows, grid = cols;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0' - 1;
                int grid_num = i / 3 * 3 + j / 3;
                if (rows[i][num] || cols[j][num] || grid[grid_num][num])
                    return false;
                else
                    rows[i][num] = cols[j][num] = grid[grid_num][num] = true;
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<char> > board(9, vector<char>(9));
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            board[i][j] = '0' + j + 1;
    Solution s;
    cout << s.isValidSudoku(board) << endl;
    return 0;
}
