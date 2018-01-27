#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int minCost(vector<vector<int>>& costs) {
    if (costs.size() == 0)
      return 0;
    vector<vector<int> > dp(costs.size(), vector<int>(3, INT_MAX));
    for (int i = 0; i < costs.size(); i++) {
      for (int j = 0; j < 3; j++) {
	if (i == 0) {
	  dp[0][j] = costs[0][j];
	  continue;
	}
	for (int k = 0; k < 3; k++) {
	  if (j == k)
	    continue;
	  dp[i][j] = min(dp[i][j], costs[i][j] + dp[i - 1][k]);
	}
      }
    }
    if (dp[costs.size() - 1][0] < dp[costs.size() - 1][1])
      return min (dp[costs.size() - 1][0], dp[costs.size() - 1][2]);
    else
      return min (dp[costs.size() - 1][1], dp[costs.size() - 1][2]);
  }
};

int main()
{
  Solution s;
  vector<vector<int> > costs = {{17,2,17},
			       {16,16,5},
			       {14,3,19}};
  cout << s.minCost(costs) << endl;
  return 0;
}
