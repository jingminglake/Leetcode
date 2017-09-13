// clang++ continuousSubarraySum.cpp -std=c++11

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    int size = nums.size();
    unordered_map<int, int> m;
    m.insert(make_pair(0,-1));
    int preSum = 0;
    for (int i = 0; i < size; i++) {
      preSum += nums[i];
      int remain = preSum;
      if (k != 0)
	remain = preSum % k;
      unordered_map<int, int>::iterator it = m.find(remain);
      if (it != m.end()) {
	if(i - it->second > 1)
	  return true;
      }
      else
	m.insert(make_pair(remain, i));
    }
    return false;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {23,2,6,4,7};
  cout << s.checkSubarraySum(nums, 6) << endl;
  return 0;
}
