#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int64_t> preSum(n + 1, 0);
        int64_t minV = 0, res = INT64_MIN;
        for (int i = 1; i <= n; i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
            res = max (res, preSum[i] - minV);
            minV = min (minV, preSum[i]);
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
