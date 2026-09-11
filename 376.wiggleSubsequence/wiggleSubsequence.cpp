// clang++ wiggleSubsequence.cpp -std=c++11

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int wiggleMaxLength(vector<int>& nums) {
    /*int size = nums.size();
    if (size == 0 || size == 1) 
      return size;
    int k = 1;
    while (k < size && nums[k] == nums[k - 1])
      k++;
    if (k == size - 1)
      return 1;
    int res = 1;
    bool ascend = nums[k] > nums[k - 1];
    int prev = nums[0];
    for (int i = 1; i < size; i++) {
      if ((ascend && nums[i] > prev) || (!ascend && nums[i] < prev)) {
	ascend = !ascend;
	res++;
      }
      prev = nums[i];
    }
    return res;*/
    int p = 1, q = 1;
    int size = nums.size();
    for (int i = 1; i < size; i++) {
      if (nums[i] > nums[i - 1])
	p = q + 1;
      else if (nums[i] < nums[i - 1])
	q = p + 1;
    }
    return max(p, q);
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
  cout << s.wiggleMaxLength(nums) << endl;;
  return 0;
}
