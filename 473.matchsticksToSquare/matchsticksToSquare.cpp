// clang++ matchsticksToSquare.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  bool makesquares(vector<int>& nums) {
    int sum = 0;
    for (int num : nums)
      sum += num;
    if (sum == 0 || sum % 4 != 0)
      return false;
    for (int num : nums)
      if (num > sum/4)
	return false;
    sort(nums.rbegin(), nums.rend());
    int part[4] = {0};
    return dfs(nums, part, 0, sum/4);
  }
  bool dfs(vector<int>& nums, int part[], int index, int edgeLength) {
    if (index == nums.size()) {
      if (part[0] == edgeLength && part[1] == edgeLength && part[2] == edgeLength)
	return true;
      return false;
    }
    for (int i = 0; i < 4; i++) {
      if (part[i] + nums[index] > edgeLength)
	continue;
      part[i] += nums[index];
      if (dfs(nums, part, index + 1, edgeLength))
	return true;
      part[i] -= nums[index];
    }
    return false;
  }
};

int main()
{
  Solution s;
  vector<int> vec = {5,5,5,5,4,4,4,4,3,3,3,3};
  cout << s.makesquares(vec);
  cout << endl;
  return 0;
}
