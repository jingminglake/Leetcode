#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        vector<int64_t> dp(n, INT_MIN);
        dp[0] = nums[0];
        dp[1] = max (nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max (dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[n - 1];
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
