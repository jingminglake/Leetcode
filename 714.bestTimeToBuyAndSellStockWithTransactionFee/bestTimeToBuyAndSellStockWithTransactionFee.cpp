#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int maxProfit(vector<int>& prices, int fee) {
    int res = 0;
    if (prices.size() < 2)
      return res;
    vector<int> hold(prices.size(), 0);
    vector<int> sold(prices.size(), 0);
    hold[0] = -prices[0];
    sold[0] = 0;
    for (int i = 1; i < prices.size(); i++) {
      hold[i] = max (hold[i - 1], sold[i - 1] - prices[i]);
      sold[i] = max (sold[i - 1], hold[i - 1] + prices[i] - fee);
    }
    return sold[prices.size() - 1];
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1,3,2,8,4,9};
  cout << s.maxProfit(nums, 2) << endl;;
  return 0;
}
