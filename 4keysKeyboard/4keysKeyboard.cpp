#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int maxA(int N) {
    vector<int> dp(N + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int k = 2; k <= N; k++) {
      dp[k] = k;
      for (int i = 1; i <= k - 3; i++)
	dp[k] = max (dp[k], dp[i] * (k - i - 1));
    }
    return dp[N];
  }
};

int main()
{
  Solution s;
  cout << s.maxA(8) << endl;
  return 0;
}
