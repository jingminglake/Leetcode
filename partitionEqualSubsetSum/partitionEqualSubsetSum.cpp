// clang++ partitionEqualSubsetSum.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if ((sum & 1) == 1) return false;
        sum /= 2;
        int size = nums.size();
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int i = 1; i <= sum; i++)
            dp[i] = false;
        for (int i = 1; i <= size; i++) {
            for (int j = sum; j >= nums[i - 1]; j--) {
                if (j >= nums[i - 1]) {
                    dp[j] = dp[j] || dp[j - nums[i - 1]];
                }
            }
        }//for
        return dp[sum];
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1,5,11,5};
    vector<int> nums2 = {1,2,3,5};
    cout << s.canPartition(nums1) << endl;
    cout << s.canPartition(nums2) << endl;
    return 0;
}
