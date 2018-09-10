#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return -1;
        vector<int64_t> global(n, INT64_MIN), local = global;
        global[0] = local[0] = nums[0];
        for (int i = 1; i < n; i++) {
            local[i] = max (local[i - 1] + nums[i], (int64_t)nums[i]);
            global[i] = max (global[i - 1], local[i]);
        }
        return global[n - 1];
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
