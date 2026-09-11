// clang++ longestIncreasingSubsequence.cpp -std=c++11

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int lengthOfLIS(vector<int>& nums) {
    int res = 1;
    int len = nums.size();
    if (len == 0)
      return 0;
    vector<int> m(len, 1);
    for (int i = 1; i < len; i++) {
      for (int j = 0; j < i; j++) {
	if (nums[j] < nums[i] && m[j] + 1 > m[i]) {
	  m[i] = m[j] + 1;
	}
      }
      res = max(res, m[i]);
    }//for
    return res;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {10,9,2,5,3,7,101,18};
  cout << s.lengthOfLIS(nums) << endl;
  return 0;
}
