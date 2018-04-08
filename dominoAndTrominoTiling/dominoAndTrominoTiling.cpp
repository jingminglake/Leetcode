#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTilings(int N) {
        int kMod = 1000000007;
        vector<vector<long> > dp(N + 1, vector<long>(2, 0));
        dp[0][0] = dp[1][0] = 1;
        for (int i = 2; i <= N; i++) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 2][0] + 2 * dp[i - 1][1]) % kMod;
            dp[i][1] = (dp[i - 2][0] + dp[i - 1][1]) % kMod;
        }
        return dp[N][0];
    }
};

int main() {
  Solution s;
  cout << s.numTilings(5) << endl;
  return 0;
}
