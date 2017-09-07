//clang++ nonDecreasingArray.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  bool checkPossibility(vector<int>& nums) {
    int size = nums.size();
    for (int i = 1; i < size; i++) {
      if (nums[i] < nums[i-1]) {
        if (i - 2 < 0 || nums[i] > nums[i-2])
	  return checkHelper(nums, i, size);
	else if (i - 2 >= 0 && nums[i] < nums[i-2]){
	  nums[i] = nums[i-1];
	  return checkHelper(nums, i + 1, size);
	}
      }
    }
    return true;
  }
  bool checkHelper(vector<int>& nums, int start, int end) {
    for (int i = start + 1; i < end; i++) {
      if (nums[i] < nums[i-1])
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
