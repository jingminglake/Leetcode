#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int size = nums.size();
    int ans = 0;
    int i = 0;
    while (i < size) {
      ans += nums[i];
      i += 2;
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int a[10] = {1, 4, 3, 2};
  vector<int> vec(a, a+4);
  cout << s.arrayPairSum(vec) << endl; 
  return 0;
}
