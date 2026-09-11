//clang++ nonDecreasingArray.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() < 2)
            return true;
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                count++;
                if (i - 2 < 0 || nums[i] >= nums[i - 2])
                    nums[i - 1] = nums[i];
                else
                    nums[i] = nums[i - 1];
            }
            if (count >= 2)
                return false;
        }
        return true;
    }
};
int main(void)
{
  Solution s;
  vector<int> nums = {3,4,2,3};
  cout << s.checkPossibility(nums) << endl;
  return 0;
}
