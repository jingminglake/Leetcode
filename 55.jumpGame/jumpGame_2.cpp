// clang++ jumpGame_2.cpp -std=c++11

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution{
public:
  bool canJump(vector<int>& nums) {
    int size = nums.size();
    int reach = 0;
    int i;
    for (i = 0; i < size && i <= reach; i++)
      reach = max(i + nums[i], reach);
    return i == size;
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
