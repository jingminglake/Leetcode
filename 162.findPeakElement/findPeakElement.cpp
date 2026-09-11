#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[len - 1] > nums[len - 2]) return len - 1;
        int left = 1, right = nums.size() - 2;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid] > nums[mid - 1]) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if (nums[left] < nums[right]) return right;
        else return left;
    }
};

int main()
{
    Solution s;
    int a[4] = {1,2,3,1};
    vector<int> vec(a, a+2);
    cout <<  s.findPeakElement(vec);
    cout << endl;
    return 0;
}
