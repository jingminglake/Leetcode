#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return 0;
        int sum = 0;
        for (int n : nums)
            sum += n;
        int newTarget = sum + target;
        if (newTarget < 0 || sum < target || newTarget % 2 != 0)
            return 0;
        newTarget /= 2;
        vector<vector<int> > dp(nums.size() + 1, vector<int>(newTarget + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j <= newTarget; j++) {
                dp[i][j] += dp[i - 1][j];
                if (j >= nums[i - 1]) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[nums.size()][newTarget];
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
