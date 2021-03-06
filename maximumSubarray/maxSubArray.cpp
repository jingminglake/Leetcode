#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp = nums;
        int res = nums[0];
        for (int i = 1; i < dp.size(); i++) {
            dp[i] = max (dp[i - 1] + nums[i], nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main()
{
    Solution s;
    int a[9] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> vec(a, a+9);
    cout << s.maxSubArray(vec) << endl; 
    return 0;
}
