#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, vector<pair<int, int> > > neighbors;
        for (auto& flight : flights)
            neighbors[flight[0]].emplace_back(flight[1], flight[2]);
        vector<vector<int> > dp(n, vector<int>(K + 2, -2));
        return dfs(src, dst, neighbors, dp, K + 1);
    }
    int dfs(int src, int dst, unordered_map<int, vector<pair<int, int> > >& neighbors, vector<vector<int> >& dp, int K) {
        if (K < 0)
            return -1;
        if (dp[src][K] != -2)
            return dp[src][K];
        if (dst == src)
            return dp[src][K] = 0;
        int price = INT_MAX;
        for (auto& n : neighbors[src]) {
            int temp = dfs(n.first, dst, neighbors, dp, K - 1);
            if (temp != -1) {
                price = min (price, temp + n.second);
            }
        }
        if (price == INT_MAX)
            dp[src][K] = -1;
        else
            dp[src][K] = price;
        return dp[src][K];
    }
};

int main () {
    int n = 3, src = 0, dst = 2, K = 1;
    vector<vector<int> > edges = {{0,1,100},{1,2,100},{0,2,500}};
    Solution s;
    cout << s.findCheapestPrice(n, edges, src, dst, K) << endl;
    return 0;
}
