#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int searchInsert(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
      int mid = low + (high - low)/2;
      if (nums[mid] < target)
	low = mid + 1;
      else if (nums[mid] > target)
	high = mid - 1;
      else
	return mid;	
    }
    return low;
  }
};

int main()
{
  Solution s;
  int a[8] = {1,3,5,6,7,8,9,10};
  vector<int> vec(a, a+8);
  cout << s.searchInsert(vec, 5) << endl;
 
  return 0;
}
