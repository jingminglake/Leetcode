#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0)
            return res;
        res = vector<int>(matrix.size() * matrix[0].size(), 0);
        int levels = matrix.size() + matrix[0].size() - 1;
        int index = 0;
        for (int i = 0; i < levels; i++) {
            if (i % 2 == 0) {
                int x = i < matrix.size() ? i : matrix.size() - 1;
                int y = i < matrix.size() ? 0 : i - (matrix.size() - 1);
                while (x >= 0 && y < matrix[0].size())
                    res[index++] = matrix[x--][y++];
            } else {
                int x = i < matrix[0].size() ? 0 : i - (matrix[0].size() - 1);
                int y = i < matrix[0].size() ? i : matrix[0].size() - 1;
                while (x < matrix.size() && y >= 0)
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
