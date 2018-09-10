// clang++ 2Keyskeyboard.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                if (i % j == 0)
                    dp[i] = min(dp[i], dp[j] + i / j);
                
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
