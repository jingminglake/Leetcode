#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = 0;
    for (int num : nums)
      sum += num;
    if (sum % k != 0)
      return false;
    vector<bool> visited(nums.size(), false);
    return dfs(nums, k, sum / k, 0, 0, visited);
  }
  bool dfs(vector<int>& nums, int k, int target, int curSum, int start, vector<bool>& visited) {
    if (k == 0)
      return true;
    if (curSum == target)
      return dfs(nums, k - 1, target, 0, 0, visited);
    for (int i = start; i < nums.size(); i++) {
      if (!visited[i]) {
	visited[i] = true;
	if (dfs(nums, k, target, curSum + nums[i], i, visited))
	  return true;
	visited[i] = false;
      }
    }
    return false;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {4,3,2,3,5,2,1};
  int k = 4;
  cout << s.canPartitionKSubsets(nums, k) << endl;
  return 0;
}
