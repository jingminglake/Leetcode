#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int res = INT_MAX;
    if (nums.size() == 0)
      return 0;
    if (nums.size() == 1)
      return nums[0] >= s;
    int left = 0, right = 0;
    int sum = nums[0];
    while (left < nums.size() && right < nums.size()) {
      if (sum < s) {
	sum += nums[++right];
      } else {
	res = min (res, right - left + 1);
	sum -= nums[left++];
      }
    }
    return res == INT_MAX ? 0 : res;
  }
};

int main()
{
  Solution s;
  int a[6] = {2,3,1,2,4,3};
  vector<int> vec(a, a+6);
  cout << s.minSubArrayLen(7, vec);
  cout << endl;
  return 0;
}
