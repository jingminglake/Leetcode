// clang++ bestTimeToBuyAndSellStockWithCooldown.cpp -std=c++11

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int maxProfit(vector<int>& prices) {
    int size = prices.size();
    if (size <= 1)
      return 0;
    vector<int> s0(size, 0);
    vector<int> s1(size, 0);
    vector<int> s2(size, 0);
    s0[0] = 0;
    s1[0] = -prices[0];
    s2[0] = INT_MIN;
    for (int i = 1; i < size; i++) {
      s0[i] = max(s0[i - 1], s2[i - 1]);
      s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
      s2[i] = s1[i - 1] + prices[i];
    }
    return max(s0[size - 1], s2[size - 1]);
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1,2,3,0,2};
  cout << s.maxProfit(nums) << endl;;
  return 0;
}
