#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int search(vector<int>& nums, int target) {
    if (nums.size() == 0)
      return -1;
    int left = 0, right = nums.size() - 1;
    while (left + 1 < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target)
	return mid;
      if (nums[mid] > nums[left] && nums[mid] > nums[right]) {
	if (target < nums[mid] && target >= nums[left])
	  right = mid;
	else
	  left = mid;
      } else {
	if (target > nums[mid] && target <= nums[right])
	  left = mid;
	else
	  right = mid;
      }
    }
    if (nums[left] == target)
      return left;
    if (nums[right] == target)
      return right;
    return -1;
  }
};

int main()
{
  Solution s;
  int a[7] = {4,5,6,7,0,1,2};
  vector<int> vec(a, a+7);
  cout << s.search(vec, 7);
  cout << endl;
  return 0;
}
