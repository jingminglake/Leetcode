#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  int subarraySum(vector<int>& nums, int k) {
    int ans = 0;
    int sum = 0;
    unordered_map<int, int> preSum;
    preSum.insert(make_pair<int, int>(0, 1));// sum == 0 : 1
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      ans += preSum[sum - k];
      preSum[sum]++;
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int a[3] = {-1,-1,1};
  vector<int> vec(a, a+3);
  cout << s.subarraySum(vec, 0);
  cout << endl;
  return 0;
}
