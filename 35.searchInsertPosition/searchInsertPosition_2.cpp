#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid;
            else if (nums[mid] > target)
                right = mid;
            else
                return mid;
        }
        if (nums[left] < target)
            return right;
        return left;
    }
};

int main()
{
    Solution s;
    int a[8] = {1,3,5,6,7,8,9,10};
    vector<int> vec(a, a+8);
    cout << s.searchInsert(vec, 5) << endl;
 
    return 0;
}
