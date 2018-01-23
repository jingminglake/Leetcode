#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int rob(vector<int>& nums) {
    int res = 0;
    if (nums.size() == 0)
      return res;
    vector<int> dp(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++) {
      dp[i] = nums[i];
      for (int j = 0; j <= i - 2; j++) {
	dp[i] = max (dp[i], dp[j] + nums[i]);
      }
      res = max (res, dp[i]);
    }
    return res;
  }
};

int main()
{
  int a[6] = {0, 0, 3, 0, 2, 0};
  vector<int> vec(a, a+6);
  Solution s;
  cout << s.rob(vec) << endl;
  return 0;
}
