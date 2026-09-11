//clang++ maximumAverageSubarrayI.cpp -std=c++11

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
  double findMaxAverage(vector<int>& nums, int k) {
    double res = 0.0, range = 0.0;
    int size = nums.size();
    if (size == 0 || size < k)
      return res;
    for (int i = 0; i < k; i++) {
      range += nums[i];
    }
    res = range;
    int left = 0, right = k - 1;
    while (right < size) {
      range += nums[++right] - nums[left++];
      res = max(res, range);
    }
    return res / k;
  }
};
int main(void)
{
  Solution s;
  vector<int> nums = {1,12,-5,-6,50,3};
  cout << s.findMaxAverage(nums, 4) << endl;
  return 0;
}
