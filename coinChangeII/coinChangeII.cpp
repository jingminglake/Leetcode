// clang++ coinChangeII.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int j = 0; j <= amount; j++) {
                if (j >= coin)
                    dp[j] += dp[j - coin];
            }
        }
        return dp[amount];
    }
};

int main()
{
    Solution s;
    vector<int> coins = {1,2,5};
    cout << s.change(11, coins) << endl;;
    return 0;
}
