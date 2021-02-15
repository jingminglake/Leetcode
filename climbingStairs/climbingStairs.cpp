#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int dp1 = 1, dp2 = 2, dp3 = 0;
        for (int i = 3; i <= n; i++) {
            dp3 = dp1 + dp2;
            dp1 = dp2;
            dp2 = dp3;
        }
        return dp3;
    }
};

int main()
{
    Solution s;
    cout << s.climbStairs(10) << endl;
    return 0;
}
