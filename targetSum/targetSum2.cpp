#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.size() == 0)
            return 0;
        int sum = 0;
        for (int n : nums)
            sum += n;
        int target = sum + S;
        if (sum < S || target % 2 != 0)
            return 0;
        target /= 2;
        vector<vector<int> > dp(nums.size() + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j <= target; j++) {
                dp[i][j] += dp[i - 1][j];
                if (j >= nums[i - 1]) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
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
