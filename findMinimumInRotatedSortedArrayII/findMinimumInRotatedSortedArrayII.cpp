#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int find(vector<int>& nums) {
    int left = 0, right = nums.size()-1;
    int mid = 0;
    while (left < right) {
      if (nums[left] < nums[right])
	return nums[left];
      mid = left + (right-left)/2;
      if (nums[mid] > nums[left])
	left = mid + 1;
      else if (nums[mid] < nums[left])
	right = mid;
      else
	left++;
    }
    return nums[left];
  }
};

int main()
{
  Solution s;
  int a[7] = {4,5,6,7,0,1,2};
  vector<int> vec(a, a+7);
  cout << s.find(vec);
  cout << endl;
  return 0;
}
