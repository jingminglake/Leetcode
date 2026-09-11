#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();
        int left = 0, right = len - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if ( (right - mid) % 2 == 0 ) {
                if (nums[mid] == nums[mid - 1]) {
                    right = mid;
                } else if (nums[mid] == nums[mid + 1]) {
                    left = mid;
                } else {
                    return nums[mid];
                }
            } else {
                if (nums[mid] == nums[mid - 1]) {
                    left = mid + 1;
                } else if (nums[mid] == nums[mid + 1]) {
                    right = mid - 1;
                } else {
                    return nums[mid];
                }
            }
            
        }
        return nums[left];
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    cout << s.singleNonDuplicate(nums) << endl;
    return 0;
}
