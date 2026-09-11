#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int res = -1;
        if (nums.size() == 0)
            return res;
        int firstMax = INT_MIN, secondMax = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > firstMax) {
                secondMax = firstMax;
                firstMax = nums[i];
                res = i;
            } else if (nums[i] > secondMax) {
                secondMax = nums[i];
            }
        }
        if (secondMax == INT_MIN)
            return 0;
        else if (firstMax >= 2 * secondMax)
            return res;
        return -1;
    }
};

int main() {
  Solution s;
  vector<int> nums = {3,6,1,0};
  cout << s.dominantIndex(nums) << endl;
  return 0;
}
