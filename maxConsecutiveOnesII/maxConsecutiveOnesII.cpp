#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int left = 0, right = 0, k = 1;
        int zero = 0;
        while (right < nums.size()) {
            if (nums[right++] == 0)
                zero++;
            while (zero > k) {
                if(nums[left++] == 0)
                    zero--;
            }
            res = max (res, right - left);
        }
        return res;
    }
};

int main() {
  Solution s;
  vector<int> nums = {1,1,0,1,1,1,0,0,1,1,1,1};
  cout << s.findMaxConsecutiveOnes(nums) << endl;
  return 0;
}
