// clang++ predictTheWinner2.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if (n % 2 == 0)
            return true;
        int64_t sum = 0;
        for (int num : nums)
            sum += num;
        vector<vector<int64_t> > dp(n, vector<int64_t>(n, -1));
        return dfs(0, n - 1, nums, dp) * 2 >= sum;
    }
    int64_t dfs(int start, int end, vector<int>& nums, vector<vector<int64_t> >& dp) {
        if (start > end)
            return 0;
        if (dp[start][end] != -1)
            return dp[start][end];
        int64_t res = 0;
        int64_t res_left = nums[start] + min ( dfs(start + 2, end, nums, dp),  dfs(start + 1, end - 1, nums, dp) );
        int64_t res_right = nums[end] + min ( dfs(start + 1, end - 1, nums, dp), dfs(start, end - 2, nums, dp) );
        res = max (res_left, res_right);
        return dp[start][end] = res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,5,233,7};
    cout << s.PredictTheWinner(nums) << endl;
    return 0;
}
