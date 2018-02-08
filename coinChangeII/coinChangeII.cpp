// clang++ coinChangeII.cpp -std=c++11

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int coin : coins) {
      for (int i = 1; i <= amount; i++) {
	if (i >= coin)
	  dp[i] += dp[i - coin];
      }
    }
    return dp[amount];
  }
};

int main()
{
  Solution s;
  vector<int> coins = {1,2,5};
  cout << s.coinChange(coins, 11) << endl;;
  return 0;
}
