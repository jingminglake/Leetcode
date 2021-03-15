#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if (nums.size() == 0) return res;
        if (nums.size() == 1) {
            if (nums[0] == target) {
                res = {0, 0};
            }
            return res;
        }
        res[0] = findFirstEqual(nums, target);
        res[1] = findLastEqual(nums, target);
        return res;
    }
    
    int findFirstEqual(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (nums[left] == target) return left;
        else if (nums[right] == target) return right;
        else return -1;
    }
    
    int findLastEqual(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (nums[right] == target) return right;
        else if (nums[left] == target) return left;
        else return -1;
    }
};

int main()
{
    Solution s;
    int a[9] = {5,7,7,8,8,8,8,10,11};
    vector<int> vec(a, a+9);
    vector<int> res = s.searchRange(vec, 8);
    for (int num : res)
        cout << num << " ";
    cout << endl;
    return 0;
}
