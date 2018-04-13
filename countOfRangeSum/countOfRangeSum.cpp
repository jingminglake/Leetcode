#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int res = 0;
        long preSum = 0;
        multiset<long> s;
        s.insert(0);
        for (int i = 0; i < nums.size(); i++) {
            preSum += nums[i];
            res += distance(s.lower_bound(preSum - upper), s.upper_bound(preSum - lower));
            s.insert(preSum);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-2, 5, -1};
    int lower = -2;
    int upper = 2;
    cout << s.countRangeSum(nums, lower, upper) << endl;
    return 0;
}
