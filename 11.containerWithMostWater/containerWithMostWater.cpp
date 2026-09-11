#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxArea = 0;
    while(left < right) {
      maxArea = max(maxArea,  (right - left) * min(height[left], height[right]));
      if(height[left] > height[right])
	 right--;
      else
	left++;	   
    }
    return maxArea;
  }
};

int main()
{
  Solution s;
  int a[4] = {1,2,3,1};
  vector<int> vec(a, a + 4);
  cout << s.maxArea(vec) << endl;
  return 0;
}
