#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        int hold1 = -prices[0];
        int hold2 = INT_MIN;
        int sold1 = 0;
        int sold2 = 0;
        for (int p : prices) {
            hold1 = max (hold1, -p);
            sold1 = max (sold1, hold1 + p);
            hold2 = max (hold2, sold1 - p);
            sold2 = max (sold2, hold2 + p);
        }
        return sold2;
    }
};

int main() {
    Solution s;
    vector<int> prices = {4,3,2,6,2,9,1,2,3};
    cout << s.maxProfit(prices) << endl;
    return 0;
}
