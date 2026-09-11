#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        while (1) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }
        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main()
{
    Solution s;
    int a[4] = {1,2,3,1};
    vector<int> vec(a, a+2);
    cout <<  s.findDuplicate(vec);
    cout << endl;
    return 0;
}
