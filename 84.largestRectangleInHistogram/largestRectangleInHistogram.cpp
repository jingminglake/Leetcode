// clang++ largestRectangleInHistogram.cpp -std=c++11

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{
public:
  int largestRectangleArea(vector<int>& heights) {
    int res = 0;
    heights.push_back(0);
    stack<int> s;
    for (int i = 0; i < heights.size(); i++) {
      while (!s.empty() && heights[s.top()] >= heights[i]) {
	int h = heights[s.top()];
	s.pop();
	int index = s.empty() ? -1 : s.top();
	res = max (res, h * (i - index - 1));
      }
      s.push(i);
    }
    return res;
  }
};

int main()
{
  Solution s;
  vector<int> heights = {2,1,5,6,2,3};
  cout << s.largestRectangleArea(heights) << endl;;
  return 0;
}
