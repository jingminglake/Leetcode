#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int minCostClimbingStairs(vector<int>& cost) {
    int size = cost.size();
    if (size == 0)
      return 0;
    if (size == 1)
      return cost[0];
    if (size == 2)
      return min(cost[0], cost[1]);
    vector<int> dp(size, INT_MAX);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < size; i++) {
      dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }
    return min(dp[size - 2], dp[size - 1]);
  }
};

int main()
{
  Solution s;
  vector<int> cost1 = {10, 15, 20};
  vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  cout << s.minCostClimbingStairs(cost1) << endl;
  cout << s.minCostClimbingStairs(cost2) << endl;
  return 0;
}
