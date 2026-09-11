// clang++ spiralMatrix.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
  vector<int> spiralOrder(vector<vector<int> >& matrix) {
    vector<int> ans;
    int m = matrix.size();
    if (m == 0)
      return ans;
    int n = matrix[0].size();
    int rowBegin = 0, rowEnd = m - 1;
    int colBegin = 0, colEnd = n - 1;
    while (rowBegin <= rowEnd && colBegin <= colEnd) {
      // traverse Right
      for (int i = colBegin; i <= colEnd; i++) {
	ans.push_back(matrix[rowBegin][i]);
      }
      rowBegin++;
      // traverse Down
      for (int i = rowBegin; i <= rowEnd; i++) {
	ans.push_back(matrix[i][colEnd]);
      }
      colEnd--;
      if (rowBegin <= rowEnd) {
	// traverse Left
	for (int i = colEnd; i >= colBegin; i--) {
	  ans.push_back(matrix[rowEnd][i]);
	}
	rowEnd--;
      }
      if (colBegin <= colEnd) {
	//travese up
	for (int i = rowEnd; i >= rowBegin; i--) {
	  ans.push_back(matrix[i][colBegin]);
	}
	colBegin++;
      }
    }//while
    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> row1 = {5,1,9,11};
  vector<int> row2 = {2,4,8,10};
  vector<int> row3 = {13,3,6,7};
  vector<int> row4 = {15,14,12,16};
  vector<vector<int> > matrix;
  matrix.push_back(row1);
  matrix.push_back(row2);
  matrix.push_back(row3);
  matrix.push_back(row4);
  vector<int> res = s.spiralOrder(matrix);
  for (int i : res) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
