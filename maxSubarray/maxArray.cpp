#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int maxSubArray(vector<int>& nums) {
    int ans = 0;
    int size = nums.size();
    vector<int> m(size,0);
    m[0] = nums[0];
    ans = m[0];
    for (int i = 1; i < size; i++) {
      m[i] = max(nums[i] + m[i-1], nums[i]);
      ans = max(m[i], ans);
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int a[9] = {-2,1,-3,4,-1,2,1,-5,4};
  vector<int> vec(a, a+9);
  cout << s.maxSubArray(vec) << endl; 
  return 0;
}
