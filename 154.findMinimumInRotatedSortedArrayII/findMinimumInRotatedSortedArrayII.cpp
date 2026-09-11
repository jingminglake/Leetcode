#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int find(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == nums[right]) {
                right--;
            }
            else if (nums[mid] >= nums[left] && nums[mid] > nums[right]) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return nums[left] < nums[right] ? nums[left] : nums[right];
    }
};

int main()
{
    Solution s;
    int a[7] = {1,1,1,1,2,1,1};
    vector<int> vec(a, a+7);
    cout << s.find(vec);
    cout << endl;
    return 0;
}
