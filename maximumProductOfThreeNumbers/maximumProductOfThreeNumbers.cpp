#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int maximumProduct(vector<int>& nums) {
    int size = nums.size();
    if (size < 3)
      return 0;
    sort(nums.begin(), nums.end());
    int a = nums[0] * nums[1] * nums[size-1];
    int ans = max(a, nums[size-3]*nums[size-2]*nums[size-1]);
    return ans;
  }
};

int main()
{
  Solution s;
  int a[4] = {1,2,3,4};
  vector<int> vec(a, a+4);
  cout << s.maximumProduct(vec);
  cout << endl;
  return 0;
}
