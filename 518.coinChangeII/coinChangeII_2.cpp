// clang++ coinChangeII_2.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int> > dp(coins.size() + 1, vector<int>(amount + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= coins.size(); i++) {
            for (int j = 0; j <= amount; j++) {
                dp[i][j] += dp[i - 1][j];
                if (j >= coins[i - 1])
                    dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
        return dp[coins.size()][amount];
    }
};

int main()
{
    Solution s;
    vector<int> coins = {1,2,5};
    cout << s.change(11, coins) << endl;;
    return 0;
}
