#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1])
                return nums[mid];
            else if (mid % 2 == 0) {
                if (nums[mid - 1] == nums[mid])
                    right = mid - 1;
                else if (nums[mid + 1] == nums[mid])
                    left = mid + 1;
            } else if (mid % 2 != 0) {
                if (nums[mid - 1] == nums[mid])
                    left = mid + 1;
                else if (nums[mid + 1] == nums[mid])
                    right = mid - 1;
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
