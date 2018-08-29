#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() < 2)
            return -1;
        int64_t sum = 0;
        for (int n : nums)
            sum += n;
        int left = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (left == sum - nums[i] - left)
                return i;
            left += nums[i];
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> ss = {1,7,3,6,5,6};
    vector<int> ss1 = {1};
    vector<int> ss2 = {1,2,3};
    cout << s.pivotIndex(ss) << endl;
    cout << s.pivotIndex(ss1) << endl;
    cout << s.pivotIndex(ss2) << endl;
    return 0;
}
