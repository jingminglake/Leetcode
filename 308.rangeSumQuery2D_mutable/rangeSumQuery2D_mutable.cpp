// clang++ rangeSumQuery2D_mutable.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        nums = matrix;
        m = matrix.size();
        if (m == 0)
            return;
        n = matrix[0].size();
        if (n == 0)
            return;
        tree = vector<vector<int> >(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                add(i, j, matrix[i][j]);
            }
        }
    }
    void add(int row, int col, int val) {
        row++;col++;
        for (int i = row; i <= m; i += lowbit(i)) {
            for (int j = col; j <= n; j += lowbit(j)) {
                tree[i][j] += val;
            }
        }
    }
    
    int lowbit(int i) {
        return i & (-i);
    }
    
    void update(int row, int col, int val) {
        int diff = val - nums[row][col];
        nums[row][col] = val;
        add(row, col, diff);
    }
    
    int getRegionSum(int row, int col) {
        int res = 0;
        for (int i = row; i > 0; i -= lowbit(i)) {
            for (int j = col; j > 0; j -= lowbit(j)) {
                res += tree[i][j];
            }
        }
        return res;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getRegionSum(row2 + 1, col2 + 1) - getRegionSum(row2 + 1, col1) - getRegionSum(row1, col2 + 1) + getRegionSum(row1, col1);
    }
    vector<vector<int> > tree;
    vector<vector<int> > nums;
    int m;
    int n;
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
