#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<int64_t> preSum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        multiset<int64_t> s;
        int res = 0;
        for (int64_t num : preSum) {
            res += distance(s.lower_bound(num - upper), s.upper_bound(num - lower));
            s.insert(num);
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
