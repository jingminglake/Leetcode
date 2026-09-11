#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size(), k = days[0].size();
        vector<vector<int>> dp(n, vector<int>(k, 0));
        return helper(flights, days, 0, 0, dp);
    }
    int helper(vector<vector<int>>& flights, vector<vector<int>>& days, int city, int day, vector<vector<int>>& dp) {
        int n = flights.size(), k = days[0].size(), res = 0;
        if (day == k) return 0;
        if (dp[city][day] > 0) return dp[city][day];
        for (int i = 0; i < n; ++i) {
            if (i == city || flights[city][i] == 1) {
                res = max(res, days[i][day] + helper(flights, days, i, day + 1, dp));
            }
        }
        return dp[city][day] = res;
    }
};

int main() {
    Solution s;
    vector<vector<int> > flights = {{0,1,1},
                                   {1,0,1},
                                   {1,1,0}};
    vector<vector<int> > days = {{1,3,1},
                                 {6,0,3},
                                 {3,3,3}};
    cout << s.maxVacationDays(flights, days) << endl;
    return 0;
}
