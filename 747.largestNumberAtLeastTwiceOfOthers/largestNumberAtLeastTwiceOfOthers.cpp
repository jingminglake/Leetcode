#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int res = -1;
        if (nums.size() == 0)
            return res;
        bool flag = true;
        long curMax = nums[0];
        res = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > curMax) {
                if (nums[i] < 2 * curMax) {
                    flag = false;
                } else {
                    flag = true;
                }
                curMax = nums[i];
                res = i;
            } else {
                if (curMax < 2 * nums[i]) {
                    flag = false;
                }
            }
        }
        if (flag)
            return res;
        else
            return -1;
    }
};

int main() {
  Solution s;
  vector<int> nums = {3,6,1,0};
  cout << s.dominantIndex(nums) << endl;
  return 0;
}
