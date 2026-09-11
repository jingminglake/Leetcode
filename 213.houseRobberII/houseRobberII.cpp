// clang++ houseRobberII.cpp -std=c++11

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    int size = nums.size();
    if (size == 0)
      return 0;
    if (size == 1)
      return nums[0];
    return max(robHelper(nums, 0, size - 2), robHelper(nums, 1, size - 1));
  }
  int robHelper(vector<int>& nums, int start, int end) {
    if (end == start)
      return nums[start];
    vector<int> dp(end - start + 1, 0);
    dp[0] = nums[start];
    dp[1] = max(nums[start], nums[start + 1]);
    for (int i = 2; i <= end - start; i++) {
      dp[i] = max(nums[start + i] + dp[i - 2], dp[i - 1]);
    }
    return dp[end - start];
  }
};

int main()
{
  Solution s;
  vector<int> nums = {7,1,3,5,8,10};
  cout << s.rob(nums) << endl;
  return 0;
}
