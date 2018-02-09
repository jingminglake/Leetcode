// clang++ maximalRectangle.cpp -std=c++11

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.size() == 0)
      return 0;
    int res = 0;
    vector<int> heights(matrix[0].size(), 0);
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
	if (matrix[i][j] == '1')
	  heights[j]++;
	else
	  heights[j] = 0;
      }
      res = max(res, longestRectangleArea(heights));
    }
    return res;
  }
  int longestRectangleArea(vector<int>& heights) {
    int res = 0;
    heights.push_back(0);
    stack<int> s;
    for (int i = 0; i < heights.size(); i++) {
      while (!s.empty() && heights[s.top()] >= heights[i]) {
	int h = heights[s.top()];
	s.pop();
	int index = s.empty() ? -1 : s.top();
	res = max (res, h * (i - 1 - index));
      }
      s.push(i);
    }
    heights.pop_back();
    return res;
  }
};

int main()
{
  Solution s;
  vector<vector<char> > matrix = {{'1', '0', '1', '0', '0'},
				  {'1', '0', '1', '1', '1'},
				  {'1', '1', '1', '1', '1'},
				  {'1', '0', '0', '1', '0'}};
  cout << s.maximalRectangle(matrix) << endl;;
  return 0;
}
