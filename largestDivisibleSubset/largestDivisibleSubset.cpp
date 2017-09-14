// clang++ largestDivisibleSubset.cpp -std=c++11

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    vector<int> res;
    sort(nums.begin(), nums.end());
    int size = nums.size();
    if (size == 0)
      return res;
    if (size == 1) {
      res.push_back(nums[0]);
      return res;
    }
    vector<int> dp(size, 1);
    vector<int> parent(size, 0);
    int maxLen = 1;
    int maxLenEndIndex = 0;
    for (int i = 1; i < size; i++) {
      for (int j = 0; j < i; j++) {
	if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
	  dp[i] = dp[j] + 1;
	  parent[i] = j;
	  if (dp[i] > maxLen) {
	    maxLen = dp[i];
	    maxLenEndIndex = i;
	  }
	}
      }//for
    }//for
    for (int i = 0; i < maxLen; i++) {
      res.push_back(nums[maxLenEndIndex]);
      maxLenEndIndex = parent[maxLenEndIndex];
    }
    return res;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1,2,3,4,8,9};
  vector<int> res = s.largestDivisibleSubset(nums);
  for (int i : res)
    cout << i << " ";
  cout << endl;
  return 0;
}
