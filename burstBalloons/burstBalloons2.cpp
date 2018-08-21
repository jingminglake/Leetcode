#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        vector<vector<int> > dp(n, vector<int>(n, -1));
        return helper(0, n - 1, nums, dp);
    }
    int helper(int start, int end, vector<int>& nums, vector<vector<int> >& dp) {
        if (start > end)
            return 0;
        if (dp[start][end] != -1)
            return dp[start][end];
        int res = 0;
        for (int i = start; i <= end; i++) {
            int bound_left = start - 1 >= 0 ? nums[start - 1] : 1;
            int bound_right = end + 1 < nums.size() ? nums[end + 1] : 1;
            int bound_product = nums[i] * bound_left * bound_right;
            res = max (res, helper(start, i - 1, nums, dp) + helper(i + 1, end, nums, dp) + bound_product);
        }
        return dp[start][end] = res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,1,5,8};
    cout << s.maxCoins(nums) << endl;
    return 0;
}
