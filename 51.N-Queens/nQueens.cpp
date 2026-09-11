#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<string> nQueens(n, string(n, '.'));
        solveNQueensHelper(res, nQueens, 0, n);
        return res;
    }
    void solveNQueensHelper(vector<vector<string> >& res, vector<string>& nQueens, int row, int& n) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (isValid(nQueens, row, col, n)) {
                nQueens[row][col] = 'Q';
                solveNQueensHelper(res, nQueens, row + 1, n);
                nQueens[row][col] = '.';
            }
        }
    }
    bool isValid(vector<string>& nQueens, int row, int col, int& n) {
        for (int i = 0; i < row; i++) {
            if (nQueens[i][col] == 'Q')
                return false;
        }
        // 45 degree diagonal in preLevels
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (nQueens[i][j] == 'Q')
                return false;
        }
        // 135 degree diagonal in preLevels
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (nQueens[i][j] == 'Q')
                return false;
        }
        return true;
    }
};

int main()
{
  Solution s;
  for (vector<string>& v : s.solveNQueens(8)) {
    for (string i : v)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}
