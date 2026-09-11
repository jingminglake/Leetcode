#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0 || matrix[0].size() == 0) return res;
        int m = matrix.size(), n = matrix[0].size();
        res = vector<int>(m * n, 0);
        int levels = m + n - 1;
        int index = 0;
        for (int i = 0; i < levels; i++) {
            if (i % 2 == 0) {
                int start_x = i < m ? i : m - 1;
                int start_y = i < m ? 0 : i - (m - 1);
                int x = start_x, y = start_y;
                while (x >= 0 && y < n)
                    res[index++] = matrix[x--][y++];
            } else {
                int start_x = i < n ? 0 : i - (n - 1);
                int start_y = i < n ? i : n - 1;
                int x = start_x, y = start_y;
                while (x < m && y >= 0)
                    res[index++] = matrix[x++][y--];
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int> > matrix1 = {{1,2,3},
                                    {4,5,6},
                                    {7,8,9}};
    vector<vector<int> > matrix2 = {{1,2},
                                    {3,4}};
    for (int n : s.findDiagonalOrder(matrix1)) {
        cout << n << ",";
    }
    cout << endl;
    for (int n : s.findDiagonalOrder(matrix2)) {
        cout << n << ",";
    }
    cout << endl;
    return 0;
}
