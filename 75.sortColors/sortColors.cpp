#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0;
        int p2 = nums.size() - 1;
        int p = 0;
        while (p <= p2) {
            if (nums[p] == 0) {
                swap(nums[p0], nums[p]);
                p0++;
                p++;
            } else if (nums[p] == 2) {
                swap(nums[p], nums[p2]);
                p2--;
            } else if (nums[p] == 1) {
                p++;
            }
        }//while
    }
};

int main()
{
    Solution s;
    int a[9] = {1,0,0,2,1,0,1,2,2};
    vector<int> nums(a, a+9);
    s.sortColors(nums);
    for (int i : nums)
        cout << i << " ";
    cout << endl;
    return 0;
}
