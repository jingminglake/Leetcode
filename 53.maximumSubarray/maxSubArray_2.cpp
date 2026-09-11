#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return -1;
        int64_t global = nums[0], local = nums[0];
        for (int i = 1; i < n; i++) {
            local = max (local + nums[i], (int64_t)nums[i]);
            global = max (global, local);
        }
        return global;
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
