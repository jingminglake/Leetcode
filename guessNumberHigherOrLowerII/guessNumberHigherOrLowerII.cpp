// clang++ guessNumberHigherOrLowerII.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int> > dp(n + 1, vector<int>(n + 1, -1));
        return helper(1, n, dp);
    }
    int helper(int start, int end, vector<vector<int> >& dp) {
        if (start >= end)
            return 0;
        if (dp[start][end] != -1)
            return dp[start][end];
        int res = INT_MAX;
        for (int i = start; i <= end; i++) {
            res = min (res, max(helper(start, i - 1, dp), helper(i + 1, end, dp)) + i);
        }
        return dp[start][end] = res;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > pairs = {{1, 2},
                                  {2, 3},
                                  {3, 4}};
    cout << s.getMoneyAmount(10) << endl;
    return 0;
}
