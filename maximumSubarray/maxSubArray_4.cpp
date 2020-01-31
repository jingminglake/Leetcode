#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int preSum = 0;
        int res = INT_MIN;
        int prevMin = 0;
        for (int i = 0; i < nums.size(); i++) {
            preSum += nums[i];
            res = max (res, preSum - prevMin);
            prevMin = min (prevMin, preSum);
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
