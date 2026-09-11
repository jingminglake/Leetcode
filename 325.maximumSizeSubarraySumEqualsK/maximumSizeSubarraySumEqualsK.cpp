#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    int res = 0;
    unordered_map<int, int> m;
    int preSum = 0;
    m[0] = -1;
    for (int i = 0; i < nums.size(); i++) {
      preSum += nums[i];
      if (m.count(preSum - k)) {
	res = max (res, i - m[preSum - k]);
      } 
      if (!m.count(preSum)){
	m[preSum] = i;
      }
    }
    return res;
  }
};

int main()
{
  Solution s;
  int a[5] = {1,-1,5,-2,3};
  vector<int> vec(a, a+5);
  cout << s.maxSubArrayLen(vec, 3);
  cout << endl;
  return 0;
}
