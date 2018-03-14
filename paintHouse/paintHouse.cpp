#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() == 0)
            return 0;
        int len = costs.size();  
        vector<vector<int> > dp(len + 1, vector<int>(3, 0));
        for(int i = 1; i <= len; i++)  
        {  
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + costs[i-1][0];  
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + costs[i-1][1];  
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + costs[i-1][2];  
        }  
        return min(dp[len][0], min(dp[len][1], dp[len][2]));  
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
