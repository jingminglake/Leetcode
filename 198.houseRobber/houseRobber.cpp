#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < dp.size(); i++) {
            int prev1 = i - 1 >= 0 ? dp[i - 1] : 0;
            int prev2 = i - 2 >= 0 ? dp[i - 2] : 0;
            dp[i] = max (prev2 + nums[i], prev1);
        }
        return dp.back();
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
