// clang++ numberOfLongestIncreasingSubsequence.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int findNumberOfLIS(vector<int>& nums) {
    int res = 0;
    int size = nums.size();
    if (size == 0)
      return res;
    vector<pair<int, int> > dp(size, {1,1}); // first: lens, second: cnts
    int maxLen = 1;
    for (int i = 1; i < size; i++) {
      for (int j = 0; j < i; j++) {
	if (nums[j] < nums[i]) {
	  if (dp[j].first + 1 == dp[i].first) {
	    dp[i].second += dp[j].second; // equals dp[j].second + 1 because dp[i].second == 1
	  }
	  if (dp[j].first + 1 > dp[i].first) {
	    dp[i].first = dp[j].first + 1;
	    dp[i].second = dp[j].second; // no need to add one, just update
	  }
	  maxLen = max(maxLen, dp[i].first);
	}
      }
    }
    for (pair<int, int>& p : dp) {
      if (p.first == maxLen)
	res += p.second;
    }
    return res;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1,3,5,4,7};
  cout << s.findNumberOfLIS(nums) << endl;
  return 0;
}
