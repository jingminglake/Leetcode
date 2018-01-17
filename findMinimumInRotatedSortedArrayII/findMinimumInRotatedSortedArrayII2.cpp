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
    cout << left << " " << right << endl;
    return nums[left];
  }
};

int main()
{
  Solution s;
  int a[7] = {1,1,1,1,2,1,1};
  vector<int> vec(a, a+7);
  cout << s.find(vec);
  cout << endl;
  return 0;
}
