// clang++ predictTheWinner2.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int> > dp(nums.size(), vector<int>(nums.size(), -1));
        helper(nums, 0, nums.size() - 1, dp);
        int sum = 0;
        for (int n : nums)
            sum += n;
        return dp[0][nums.size() - 1] * 2 >= sum;
    }
    int helper(vector<int>& nums, int start, int end, vector<vector<int> >& dp) {
        if (start > end)
            return 0;
        if (dp[start][end] != -1)
            return dp[start][end];
        if (start == end)
            return dp[start][end] = nums[start];
        int left_max = nums[start] + min (helper(nums, start + 2, end, dp), helper(nums, start + 1, end - 1, dp));
        int right_max = nums[end] + min (helper(nums, start + 1, end - 1, dp), helper(nums, start, end - 2, dp));
        return dp[start][end] = max (left_max, right_max);
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,5,233,7};
    cout << s.PredictTheWinner(nums) << endl;
    return 0;
}
