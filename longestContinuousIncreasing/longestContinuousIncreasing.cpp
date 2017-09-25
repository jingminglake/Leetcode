// clang++ longestContinuousIncreasing.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int findLengthOfLCIS(vector<int>& nums) {
    int res = 0;
    int size = nums.size();
    if (size == 0)
      return res;
    int dp = 1;
    res = 1;
    for (int i = 1; i < size; i++) {
      if (nums[i] > nums[i - 1]) {
	dp += 1;
	res = max (res, dp);
      } else {
	dp = 1;
      }
    }
    return res;
  }
};

int main()
{
  Solution s;
  vector<int> nums1 = {1,3,5,4,7};
  vector<int> nums2 = {2,2,2,2,2};
  cout << s.findLengthOfLCIS(nums1) << endl;
  cout << s.findLengthOfLCIS(nums2) << endl;
  return 0;
}
