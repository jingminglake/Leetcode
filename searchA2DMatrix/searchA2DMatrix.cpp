// clang++ searchA2DMatrix.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
  bool searchMatrix(vector<vector<int> >& matrix, int target) {
    if (matrix.size() == 0)
      return false;
    vector<int> col0;
    for (int i = 0; i < matrix.size(); i++) {
      if (matrix[i].size())
	col0.push_back(matrix[i][0]);
    }
    pair<int, bool> p = binarySearch(col0, target);
    if (p.second)
      return true;
    if (p.first >= 0)
      return binarySearch(matrix[p.first], target).second;
    return false;
  }
  pair<int, bool> binarySearch(vector<int>& vec, int target) {
    pair<int, bool> res;
    int left = 0, right = vec.size() - 1;
    while (left <= right) {
      int mid = left  + (right - left) / 2;
      if (vec[mid] == target) {
	res = make_pair(mid, true);
	return res;
      } else if (vec[mid] < target) {
	left = mid + 1;
      } else if (vec[mid] > target) {
	right = mid - 1;
      }
    }
    res = make_pair(right, false);
    return res;
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
