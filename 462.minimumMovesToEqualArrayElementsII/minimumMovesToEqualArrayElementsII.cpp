// clang++ minimumMovesToEqualArrayElementsII.cpp -std=c++11

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;


class Solution{
public:
  int minMoves2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int i = 0, j = nums.size() - 1;
    int ans = 0;
    while (i < j) {
      ans += nums[j] - nums[i];
      i++;
      j--;
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1,2,99};
  cout << s.minMoves2(nums);
  cout << endl;
  return 0;
}
