#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int triangleNumber(vector<int>& nums) {
    int ans = 0;
    int size =  nums.size();
    sort(nums.begin(), nums.end());
    for (int i = size-1; i >= 2; i--) {
      int left = 0, right = i - 1;
      while (left < right) {
	if (nums[right] + nums[left] > nums[i]) {
	  ans += right - left;
 	  right--;
	} else	
	  left++;
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int a[4] = {2,2,3,4};
  vector<int> vec(a, a+4);
  cout << s.triangleNumber(vec);
  cout << endl;
  return 0;
}
