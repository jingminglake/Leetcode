#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_map<int, bool> > dp;
        return dfs(0, 0, stones, dp);
    }
    bool dfs(int start_index, int k, vector<int>& stones, unordered_map<int, unordered_map<int, bool> >& dp) {
        if (start_index == stones.size() - 1)
            return true;
        if (dp.count(start_index) && dp[start_index].count(k))
            return dp[start_index][k];
        for (int i = start_index + 1; i < stones.size(); i++) {
            int gap = stones[i] - stones[start_index];
            if (gap == k - 1 && dfs(i, k - 1, stones, dp))
                return dp[start_index][k] = true;
            else if (gap == k && dfs(i, k, stones, dp))
                return dp[start_index][k] = true;
            else if (gap == k + 1 && dfs(i, k + 1, stones, dp))
                return dp[start_index][k] = true;
        }
        return dp[start_index][k] = false;
    }
};

int main() {
    Solution s;
    vector<int> stones = {0,1,3,5,6,8,12,17};
    cout << s.canCross(stones) << endl;
    return 0;
}
