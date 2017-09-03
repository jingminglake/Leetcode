// clang++ setMatrixZeroes.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
  void setZeroes(vector<vector<int> >& matrix) {
    int m = matrix.size();
    if (m == 0)
      return;
    int n = matrix[0].size();
    bool rowZero = false, colZero = false;
    for (int i = 0; i < m; i++) {
      if (matrix[i][0] == 0) {
	colZero = true;
	break;
      }
    }
    for (int i = 0; i < n; i++) {
      if (matrix[0][i] == 0) {
	rowZero = true;
	break;
      }
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
	if (matrix[i][j] == 0) {
	  matrix[i][0] = 0;
	  matrix[0][j] = 0;
	}
      }
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
	if (matrix[i][0] == 0 || matrix[0][j] == 0) {
	  matrix[i][j] = 0;
	}
      }
    }
    if (rowZero) {
      for (int i = 0; i < n; i++)
	matrix[0][i] = 0;
    }
    if (colZero) {
      for (int i = 0; i < m; i++)
	matrix[i][0] = 0;
    }
  }
};

int main()
{
  Solution s;
  vector<int> row1 = {5,1,0,11};
  vector<int> row2 = {2,4,8,10};
  vector<int> row3 = {0,3,6,7};
  vector<int> row4 = {15,14,12,16};
  vector<vector<int> > matrix;
  matrix.push_back(row1);
  matrix.push_back(row2);
  matrix.push_back(row3);
  matrix.push_back(row4);
  s.setZeroes(matrix);
  int rowLen = matrix.size();
  int colLen = matrix[0].size();
  for (int i = 0; i < rowLen; i++) {
    for (int j = 0; j < colLen; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
