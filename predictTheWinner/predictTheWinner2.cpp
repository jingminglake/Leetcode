// clang++ predictTheWinner2.cpp -std=c++11

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int> > dp(nums.size(), vector<int>(nums.size(), -1));
        long mostVal = getMost(nums, dp, 0, nums.size() - 1);
        return 2 * mostVal >= accumulate(nums.begin(), nums.end(), 0);
    }
    int getMost(vector<int>& nums, vector<vector<int> >& dp, int i, int j) {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int a = nums[i] + min (getMost(nums, dp, i + 1, j - 1), getMost(nums, dp, i + 2, j));
        int b = nums[j] + min (getMost(nums, dp, i + 1, j - 1), getMost(nums, dp, i, j - 2));
        dp[i][j] = max (a, b);
        return dp[i][j];
    }
};

int main()
{
  Solution s;
  vector<int> nums = {1,5,233,7};
  cout << s.PredictTheWinner(nums) << endl;
  return 0;
}
