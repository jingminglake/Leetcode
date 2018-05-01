// clang++ rangeSumQuery2D_mutable.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
public:
    vector<vector<int> > tree;
    vector<vector<int> > nums;
    int m;
    int n;
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return;
        m = matrix.size();
        n = matrix[0].size();
        tree = vector<vector<int> > (m + 1, vector<int>(n + 1, 0));
        nums = vector<vector<int> > (m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                update(i, j, matrix[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        if (m == 0 || n == 0)
            return;
        int diff = val - nums[row][col];
        nums[row][col] = val;
        for (int i = row + 1; i <= m; i += (i & (-i))) {
            for (int j = col + 1; j <= n; j += (j & (-j))) {
                tree[i][j] += diff;
            }
        }
    }
    int getSum(int row, int col) {
        int sum = 0;
        for (int i = row; i > 0; i -= i & (-i)) {
            for (int j = col; j > 0; j -= j & (-j)) {
                sum += tree[i][j];
            }
        }
        return sum;
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (m == 0 || n == 0)
            return 0;
        return getSum (row2 + 1, col2 + 1) - getSum (row1, col2 + 1) - getSum (row2 + 1, col1) + getSum (row1, col1);
    }
};

int main()
{
  vector<vector<int> > matrix = {{3,0,1,4,2},
				 {5,6,3,2,1},
                                 {1,2,0,1,5},
                                 {4,1,0,1,7},
                                 {1,0,3,0,5}};
  NumMatrix objMatrix(matrix);
  //cout << objMatrix.sumRegion(2,1,4,3) << endl;
  cout << objMatrix.sumRegion(1,1,2,2) << endl;
  objMatrix.update(1, 2, 100);
  cout << objMatrix.sumRegion(1,1,2,2) << endl;
  //cout << objMatrix.sumRegion(1,2,2,4) << endl;
  return 0;
}
