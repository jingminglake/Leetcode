#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int findMin(vector<int>& nums) {
    int left = 0, right = nums.size()-1;
    while (left < right) {
      if (nums[left] < nums[right])
	return nums[left];
      int mid = left + (right-left)/2;
      if (nums[mid] >= nums[left]) {
	left = mid + 1;
      } else {
	right = mid;
      }
    }
    return nums[left];
  }
};

int main()
{
  Solution s;
  int a[7] = {4,5,6,7,0,1,2};
  vector<int> vec(a, a+7);
  cout << s.findMin(vec);
  cout << endl;
  return 0;
}
