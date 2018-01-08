// clang++ searchA2DMatrixII.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
  bool searchMatrix(vector<vector<int> >& matrix, int target) {
    if (matrix.size() == 0)
      return false;
    int i = 0;
    int j = matrix[0].size() - 1;
    while (j >= 0 && i <= matrix.size() - 1) {
      if (matrix[i][j] == target)
	return true;
      else if (matrix[i][j] > target)
	j--;
      else if (matrix[i][j] < target)
	i++;
    }
    return false;
  }
};

int main()
{
  Solution s;
  vector<int> row1 = {1,4,7,11,15};
  vector<int> row2 = {2,5,8,12,19};
  vector<int> row3 = {3,6,9,16,22};
  vector<int> row4 = {10,13,14,17,24};
  vector<int> row5 = {18,21,23,26,30};
  vector<vector<int> > matrix;
  matrix.push_back(row1);
  matrix.push_back(row2);
  matrix.push_back(row3);
  matrix.push_back(row4);
  matrix.push_back(row5);
  cout << s.searchMatrix(matrix, 5) << endl;
  cout << s.searchMatrix(matrix, 20) << endl;
  return 0;
}
