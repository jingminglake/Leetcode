// clang++ predictTheWinner.cpp -std=c++11

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  bool predictTheWinner(vector<int>& nums) {
    int size = nums.size();
    vector<vector<int> > dp(size, vector<int>(size, -1)); // dp[i,j] means the final if one player get first in range i to j, for the player the value is postive,for another player who get is minus 
    return canWin(nums, 0, size - 1, dp) >= 0;
  }
  int canWin(vector<int>& nums, int start, int end, vector<vector<int> >& dp) {
    if (dp[start][end] == -1) {
      if (start == end)
	dp[start][end] = nums[start];
      else
	dp[start][end] = max (nums[start] - canWin(nums, start + 1, end, dp), nums[end] - canWin(nums, start, end - 1, dp));
    }
    return dp[start][end];
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1,5,233,7};
  cout << s.predictTheWinner(nums) << endl;
  return 0;
}
