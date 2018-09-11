// clang++ longestContinuousIncreasingSubsequence.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int res = 1;
        int dp = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                dp++;
                res = max (res, dp);
            } else {
                dp = 1;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1,3,5,4,7};
    vector<int> nums2 = {2,2,2,2,2};
    cout << s.findLengthOfLCIS(nums1) << endl;
    cout << s.findLengthOfLCIS(nums2) << endl;
    return 0;
}
