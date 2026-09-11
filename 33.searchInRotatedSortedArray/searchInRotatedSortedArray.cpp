#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int left = 0, right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                if (nums[mid] < target) {
                    left = mid;
                } else if (nums[mid] > target) {
                    if (target >= nums[left]) right = mid;
                    else left = mid;
                } else {
                    return mid;
                }
            } else if (nums[mid] < nums[right]) {
                if (nums[mid] < target) {
                    if (target <= nums[right]) left = mid;
                    else right = mid;
                } else if (nums[mid] > target) {
                    right = mid;
                } else {
                    return mid;
                }
            } else {
                return mid;
            }
        }
        if (nums[left] == target) return left;
        if (nums[right] == target) return right;
        return -1;
    }
};

int main()
{
    Solution s;
    int a[7] = {4,5,6,7,0,1,2};
    vector<int> vec(a, a+7);
    cout << s.search(vec, 7);
    cout << endl;
    return 0;
}
