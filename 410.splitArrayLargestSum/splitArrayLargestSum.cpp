#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        if (nums.size() == 1) return nums[0];
        long left = nums[0], right = 0;
        for (int n : nums) {
            if (n > left) left = n;
            right += n;
        }
        while (left + 1 < right) {
            long mid = left + (right - left) / 2;
            if (lessEqualM(nums, m, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (lessEqualM(nums, m, left)) return (int)left;
        else if (lessEqualM(nums, m, right)) return (int)right;
        else return -1;
    }
    
    bool lessEqualM(vector<int>& nums, int m, long mid) {
        int n = 0;
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            if (i == nums.size() - 1 || cur + nums[i + 1] > mid) {
                cur = 0;
                if (++n > m) return false; 
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {7,2,5,10,8};
    cout << s.splitArray(nums, 2);
    cout << endl;
    return 0;
}
