// clang++ uniquePaths_2.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1)
                    dp[j] = 1;
                else
                    dp[j] += dp[j - 1];
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    cout << s.uniquePaths(2,1) << endl;;
    return 0;
}
