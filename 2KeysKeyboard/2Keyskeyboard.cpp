// clang++ 2Keyskeyboard.cpp -std=c++11

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int minSteps(int n) {
    if (n <= 1)
      return 0;
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      dp[i] = i;
      for (int j = 2; j < i; j++) {
	if (i % j == 0) {
	  dp[i] = min(dp[i], dp[j] + i/j);
	}
      }
    }
    return dp[n];
  }
};

int main()
{
  Solution s;
  cout << s.minSteps(100) << endl;
  return 0;
}
