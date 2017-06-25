#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int search(vector<int>& nums, int target) {
    int diff = 0;
    int size = nums.size();
    int left = 0, right = size - 1;
    int mid = 0;
    while (left < right) {
      if (nums[left] < nums[right])
	break;
      mid = left + (right-left)/2;
      if (nums[mid] >= nums[left])
	left = mid + 1;
      else
	right = mid;
    }
    diff = left;
    left = 0;
    right = size - 1;
    while (left <= right) {
      mid = left + (right-left)/2;
      int realMid = (mid + diff)%size;
      if (nums[realMid] < target)
	left = mid + 1;
      else if (nums[realMid] > target)
	right = mid - 1;
      else
	return realMid;
    }
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
