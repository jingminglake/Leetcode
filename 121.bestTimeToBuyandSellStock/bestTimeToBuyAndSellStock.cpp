#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int prevMin = INT_MAX;
        for (int p : prices) {
            if (p > prevMin) {
                res = max (res, p - prevMin);
            } else {
                prevMin = p;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    int a[6] = {7, 1, 5, 3, 6, 4};
    vector<int> vec(a, a+6);
    cout << s.maxProfit(vec) << endl;
    return 0;
}
