#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 1 && nums[i] <= n) {
                if (nums[nums[i] - 1] != nums[i]) {
                    swap(nums[i], nums[nums[i] - 1]);
                    i--;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,4,-1,1};
    cout << s.firstMissingPositive(nums) << endl;
    return 0;
}
