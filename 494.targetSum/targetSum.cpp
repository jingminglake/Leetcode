#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution{
public:
  int findTargetSumWays(vector<int>& nums, int S) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    return sum < S || (S + sum) & 1 ? 0 : subsetSum(nums, (S + sum) >> 1);
  }
  int subsetSum(vector<int>& nums, int target) {
    vector<int> m(target+1, 0);
    m[0] = 1;
    for (int n : nums)
      for (int i = target; i >= n;i--)
	m[i] += m[i-n];
    return m[target];
  }
};

int main()
{
  Solution s;
  vector<int> vec(5, 1);
  cout << s.findTargetSumWays(vec, 3);
  cout << endl;
  return 0;
}
