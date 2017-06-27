#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int findPeakElement(vector<int>& nums) {
    int size = nums.size();
    /* if (size < 1)
      return -1;
    if (size == 1)
      return 0;
    int prev = nums[0];
    for (int i = 0; i < size; i++) {
      if (i == 0 && size == 2 && nums[i] > nums[i+1])
	return 0;
      else if (i == size-1 && size == 2 && nums[i] > nums[i-1])
	return 1;
      else if (i - 1 >= 0 && i + 1 <= size - 1 && nums[i] > nums[i-1] && nums[i]> nums[i+1])
	return i;
      else if (i - 1 >= 0 && i + 1 > size - 1 && nums[i] > nums[i-1])
	return i;
      else if (i - 1 < 0 && i + 1 <= size - 1 && nums[i]> nums[i+1])
	return i;
	
	}*/
    /* for (int i  = 1; i < size; i++) {
      if (nums[i] < nums[i-1])
	return i-1;
    }
    return size-1;*/
    int left = 0, right = size - 1;
    int mid = 0;
    while (left < right) {
      mid = left + (right-left)/2;
      if (nums[mid] > nums[mid+1])
	right = mid;
      else
	left = mid + 1;
    }
    return left;
  }
};

int main()
{
  Solution s;
  int a[4] = {1,2,3,1};
  vector<int> vec(a, a+2);
  cout <<  s.findPeakElement(vec);
  cout << endl;
  return 0;
}
