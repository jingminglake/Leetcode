// clang++ coinChange.cpp -std=c++11

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<long> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
      for (int coin : coins) {
	if (i >= coin) {
	  dp[i] = min (dp[i], dp[i - coin] + 1);
	}
      }
    }
    return dp[amount] >= INT_MAX ? -1 : dp[amount];
  }
};

int main()
{
  Solution s;
  vector<int> coins = {1,2,5};
  cout << s.coinChange(coins, 11) << endl;;
  return 0;
}
