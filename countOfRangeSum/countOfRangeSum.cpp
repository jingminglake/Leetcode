#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.size() == 0)
            return 0;
        vector<int64_t> pre_sum;
        int64_t sum = 0;
        for (int n : nums) {
            sum += n;
            pre_sum.push_back(sum);
        }
        int res = 0;
        multiset<int64_t> s;
        s.insert(0);
        for (int64_t n : pre_sum) {
            res += distance(s.lower_bound(n - upper), s.upper_bound(n - lower));
            s.insert(n);
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
