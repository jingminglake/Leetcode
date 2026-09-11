#include <iostream>
using namespace std;

class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0)
            return 0;
        if (n == 1)
            return k;
        if (n == 2)
            return k * k;
        int dp = 0;
        int dp1 = k * k;
        int dp2 = k;
        for (int i = 2; i < n; i++) {
            dp = (dp1 + dp2) * (k - 1);
            dp2 = dp1;
            dp1 = dp;
        }
        return dp;
    }
};

int main() {
  Solution s;
  cout << s.numWays(4, 6) << endl;
  return 0;
}
