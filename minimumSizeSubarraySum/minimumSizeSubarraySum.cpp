#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int ans = INT_MAX;
    int size = nums.size();
    int sum = 0;
    int start = 0;
    for (int i = 0; i < size; i++) {
      sum += nums[i];
      while (sum > s) {
        ans = min(ans, i - start + 1);
	sum -= nums[start++];
      }
    }
    return ans == INT_MAX ? 0 : ans;
  }
};

int main()
{
  Solution s;
  int a[6] = {2,3,1,2,4,3};
  vector<int> vec(a, a+6);
  cout << s.minSubArrayLen(7, vec);
  cout << endl;
  return 0;
}
