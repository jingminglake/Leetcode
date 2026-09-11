#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int n = nums.size();
        vector<int> new_nums(n + 2);
        for (int i = 0; i < n; i++)
            new_nums[i + 1] = nums[i];
        new_nums[0] = new_nums[n + 1] = 1;
        vector<vector<int> > dp(n + 2, vector<int>(n + 2, -1));
        return dfs (new_nums, 1, n, dp);
    }
    int dfs (vector<int>& nums, int start, int end, vector<vector<int> >& dp) {
        if (start == end) {
            return dp[start][end] = nums[start - 1] * nums[start] * nums[end + 1];
        }
        if (dp[start][end] != -1)
            return dp[start][end];
        int res = 0;
        int bound_product = nums[start - 1] * nums[end + 1];
        for (int i = start; i <= end; i++) {
            res = max (res,  nums[i] * bound_product + dfs(nums, start, i - 1, dp) + dfs(nums, i + 1, end, dp));
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
