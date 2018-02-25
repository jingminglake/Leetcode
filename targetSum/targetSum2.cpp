#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int S) {
    int res = 0;
    int sum = 0;
    for (int num : nums) {
      sum += num;
    }
    int target = S + sum;
    if (sum < S || target % 2 != 0)
      return res;
    target /= 2;
    //cout << target << endl;
    vector<vector<int> > dp(nums.size() + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= nums.size(); i++) {
      for (int j = 0; j <= target; j++) { 
	if (j >= nums[i - 1])
	  dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
	else 
	  dp[i][j] = dp[i - 1][j];
      }
    }
    return dp[nums.size()][target];
  }
};

int main()
{
  Solution s;
  vector<int> vec(5, 1);
  cout << s.findTargetSumWays(vec, 3);
  cout << endl;
  return 0;
}
