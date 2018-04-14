#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        if (k >= prices.size() / 2) {
            return quickSolve(prices);
        }
        vector<int> global(k + 1, 0);
        vector<int> local(k + 1, 0);
        for (int i = 0; i < prices.size() - 1; i++) {
            int diff = prices[i + 1] - prices[i];
            for (int j = k; j >= 1; j--) {
                local[j] = max (global[j - 1] + max (0, diff), local[j] + diff);
                global[j] = max (global[j], local[j]);
            }
        }
        return global[k];
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
