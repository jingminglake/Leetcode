// clang++ combinationSumIV.cpp -std=c++11

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    int size = nums.size();
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= target; i++) {
      for (int j = 0; j < size; j++) {
	if (i >= nums[j])
	  dp[i] += dp[i - nums[j]];
      }
    }//for
    return dp[target];
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 2, 3};
  cout << s.combinationSum4(nums, 4) << endl;
  return 0;
}
