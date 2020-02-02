#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int res = 0;
        if (nums.size() == 0) return res;
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < dp.size(); i++) {
            int prev1 = i - 2 >= 0 ? dp[i - 2] : 0;
            int prev2 = i - 3 >= 0 ? dp[i - 3] : 0;
            dp[i] = max (prev1, prev2) + nums[i];
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
