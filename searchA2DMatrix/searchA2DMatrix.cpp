// clang++ searchA2DMatrix.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
  bool searchMatrix(vector<vector<int> >& matrix, int target) {
    int m = matrix.size();
    if (m == 0)
      return false;
    int n = matrix[0].size();
    if (n == 0)
      return false;
    int low = 0, high = m - 1;
    while (low <= high) {
      int mid = low + (high - low)/2;
      if (matrix[mid][0] < target)
	low = mid + 1;
      else if (matrix[mid][0] > target)
	high = mid - 1;
      else
	return true;
    }
    if (high < 0) {
      return false;
    }
    int left = 0, right = n - 1;
    while (left <= right) {
      int mid = left + (right - left)/2;
      if (matrix[high][mid] < target)
	left = mid + 1;
      else if (matrix[high][mid] > target)
	right = mid - 1;
      else
	return true;
    }
    return false;
  }
};

int main()
{
  Solution s;
  vector<int> row1 = {1,3,5,7};
  vector<int> row2 = {10,11,16,20};
  vector<int> row3 = {23,30,34,50};
  vector<int> row4 = {30,32,38,61};
  vector<vector<int> > matrix;
  matrix.push_back(row1);
  matrix.push_back(row2);
  matrix.push_back(row3);
  matrix.push_back(row4);
  cout << s.searchMatrix(matrix, 3) << endl;
  return 0;
}
