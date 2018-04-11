#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double soupServings(int N) {
        if (N > 4800)
            return 1.0;
        vector<vector<double> > dp((N + 24) / 25 + 1, vector<double>((N + 24) / 25 + 1, -1.0));
        return dfs((N + 24) / 25, (N + 24) / 25, dp);
    }
    double dfs(int NA, int NB, vector<vector<double> >& dp) {
        if (NA <= 0 && NB <= 0)
            return 0.5;
        else if (NA <= 0)
            return 1;
        else if (NB <= 0)
            return 0;
        if (dp[NA][NB] > 0)
            return dp[NA][NB];
        dp[NA][NB] = 0.25 * (dfs(NA - 4, NB, dp) + dfs(NA - 3, NB - 1, dp) + dfs(NA - 2, NB - 2, dp) + dfs(NA - 1, NB - 3, dp));
        return dp[NA][NB];
    }
};

int main() {
  Solution s;
  cout << s.soupServings(300) << endl;
  return 0;
}
