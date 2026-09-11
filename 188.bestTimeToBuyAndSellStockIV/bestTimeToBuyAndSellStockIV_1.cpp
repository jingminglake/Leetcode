// time: O(n * n * k)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
         if (n == 0)
            return 0;
        if (k >= n / 2) {
            return quickSolve(prices);
        }
        int res = 0;
        vector<vector<int> > dp(n, vector<int>(k + 1, 0));
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];
                for (int x = 0; x < i; x++) {
                    dp[i][j] = max (dp[i][j], dp[x][j - 1] + prices[i] - prices[x]);
                }
            }
        }
        return dp[n - 1][k];
    }
    int quickSolve(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1])
                res += prices[i] - prices[i - 1];
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> prices = {3,4,1,2,5,6,3,2,1,5,7,3};
    int k = 4;
    cout << s.maxProfit(4, prices) << endl;
    return 0;
}
