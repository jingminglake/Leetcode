#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        long minV = nums[0], maxV = nums[0];
        for (long n : nums) {
            minV = min (minV, n);
            maxV = max (maxV, n);
        }
        int range = (maxV - minV) / nums.size() + 1;
        vector<long> minBucket(nums.size(), LONG_MAX);
        vector<long> maxBucket(nums.size(), LONG_MIN);
        for (long n : nums) {
            int index = (n - minV) / range;
            minBucket[index] = min (minBucket[index], n);
            maxBucket[index] = max (maxBucket[index], n);
        }
        long res = LONG_MIN;
        long prev = maxBucket[0];
        for (int i = 1; i < nums.size(); i++) {
            if (minBucket[i] != LONG_MAX) { // minBucket[i] != LONG_MAX => maxBucket[i] != LONG_MIN
                res = max (res, minBucket[i] - prev);
                prev = maxBucket[i]; // prev need not update when maxBucket[i] == LONG_MIN
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,9,6,1};
    cout << s.maximumGap(nums) << endl;
    return 0;
}
