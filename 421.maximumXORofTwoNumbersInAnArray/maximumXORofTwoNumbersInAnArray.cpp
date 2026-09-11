//clang++ maximumXORofTwoNumbersInAnArray.cpp -std=c++11
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
  int findMaximumXOR(vector<int>& nums) {
    int res = 0, mask = 0;
    for (int i = 31; i >= 0; i--) {
      mask |= (1 << i);
      unordered_set<int> s;
      for (int num : nums)
	s.insert(num & mask);
      int t = res | (1 << i);
      for (int prefix : s) {
	if (s.count(t ^ prefix)) {
	  res = t;
	  break;
	}
      }
    }//for
    return res;
  }
};
int main(void)
{
  Solution s;
  vector<int> nums = {3,10,5,25,2,8};
  cout << s.findMaximumXOR(nums) << endl;
  return 0;
}
