#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1, res = 0, i = 0;
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss += miss;
                res++;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,5,10};
    int n = 20;
    cout << s.minPatches(nums, n);
    cout << endl;
    return 0;
}
