#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int minMoves(vector<int>& nums) {
    int sum = 0, minE = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      minE = min(minE, nums[i]);
    }
    return sum - nums.size() * minE;
  }
};

int main()
{
  Solution s;
  int a[3] = {1,2,3};
  vector<int> vec(a, a+3);
  cout << s.minMoves(vec) << endl;
  return 0;
}
