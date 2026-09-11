// clang++ jumpGame.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
  bool canJump(vector<int>& nums) {
    return canJumpHelper(nums, nums.size() - 1);
  }
  bool canJumpHelper(vector<int>& nums, int lastIndex) {
    if (lastIndex < 1)
      return true;
    int step = 0;
    bool canJump = false;
    for (int i = lastIndex - 1; i >= 0; i--) {
      if (nums[i] >= ++step) {
	canJump = true;
	lastIndex = i;
	break;
      }
    }
    if (canJump)
      return canJumpHelper(nums, lastIndex);
    else
      return false;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {2,3,1,1,4};
  vector<int> nums2 = {3,2,1,0,4};
  vector<int> nums3 = {0,1};
  vector<int> nums4 = {0};
  cout << s.canJump(nums) << endl;
  cout << s.canJump(nums2) << endl;
  cout << s.canJump(nums3) << endl;
  cout << s.canJump(nums4) << endl;
  return 0;
}
