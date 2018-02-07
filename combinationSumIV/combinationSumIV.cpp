// clang++ combinationSumIV.cpp -std=c++11

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    sort(nums.begin(), nums.end());
    for (int i = 1; i <= target; i++) {
      for (int num : nums) {
	if (num > i)
	  break;
	dp[i] += dp[i - num];
      }
    }
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
