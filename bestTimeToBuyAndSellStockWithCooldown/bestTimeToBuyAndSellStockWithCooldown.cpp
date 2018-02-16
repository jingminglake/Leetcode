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
    vector<int> rest(size, 0);
    vector<int> hold(size, 0);
    vector<int> sold(size, 0);
    rest[0] = 0;
    hold[0] = -prices[0];
    sold[0] = INT_MIN;
    for (int i = 1; i < size; i++) {
      rest[i] = max(rest[i - 1], sold[i - 1]);
      hold[i] = max(hold[i - 1], rest[i - 1] - prices[i]);
      sold[i] = hold[i - 1] + prices[i];
    }
    return max(rest[size - 1], sold[size - 1]);
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1,2,3,0,2};
  cout << s.maxProfit(nums) << endl;;
  return 0;
}
