#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  int maxProduct(vector<int>& nums) {
    int res = 0;
    if (nums.size() == 0)
      return res;
    int maxHere = nums[0];
    int minHere = nums[0];
    res = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      int prevMax = maxHere;
      maxHere = max (nums[i], max (nums[i] * maxHere, nums[i] * minHere) );
      minHere = min (nums[i], min (nums[i] * prevMax, nums[i] * minHere) );
      res = max (res, maxHere);
    }
    return res;
  }
};

int main()
{
  Solution s;
  int a[4] = {2,3,-2,4};
  vector<int> vec(a, a+4);
  cout << s.maxProduct(vec);
  cout << endl;
  return 0;
}
