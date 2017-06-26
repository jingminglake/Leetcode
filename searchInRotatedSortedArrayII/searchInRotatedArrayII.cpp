#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  bool search(vector<int>& nums, int target) {
   /* method one : first find minIndex, then binary search
    int diff = 0;
    int size = nums.size();
    int left = 0, right = size-1;
    int mid = 0;
    while (left < right) {
      mid = left + (right-left)/2;
      if (nums[mid] > nums[right])
	left = mid+1;
      else if (nums[mid] < nums[right])
	right = mid;
      else {
	if (nums[right-1] > nums[right]) {
	  left = right;
	  break;
	}
	right--;
      }
    }
    //cout << left << " " << right << endl;
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
	return true;
    }
    return false;*/
    int size = nums.size();
    int left = 0, right = size-1;
    int mid = 0;
    while (left <= right) {
      mid = left + (right-left)/2;
      if (nums[mid] == target)
	return true;
      else if (nums[mid] < nums[right]) {
	if (target > nums[mid] && target <= nums[right])
	  left = mid + 1;
	else
	  right = mid - 1;
      } else if (nums[mid] > nums[right]){
	if (target >= nums[left] && target < nums[mid])
	  right = mid - 1;
	else
	  left = mid + 1;
      } else
	right--;
    }
    return false;
  }
};

int main()
{
  Solution s;
  int a[7] = {1,1,5,2,1,1,1};
  vector<int> vec(a, a+7);
  cout << s.search(vec, 1);
  cout << endl;
  return 0;
}
