#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones.size() == 0)
            return false;
        unordered_map<string, bool> dp;
        return dfs(0, 0, stones, dp);
    }
    bool dfs(int i, int k, vector<int>& stones, unordered_map<string, bool>& dp) {
        string key = to_string(i) + to_string(k);
        if (dp.count(key))
            return dp[key];
        if (i == stones.size() - 1)
            return dp[key] = true;
        if (k < 0)
            return dp[key] = false;
        for (int j = i + 1; j < stones.size(); j++) {
            int gap = stones[j] - stones[i];
            if (gap == k - 1 && dfs(j, k - 1, stones, dp))
                    return true;
            else if (gap == k && dfs(j, k, stones, dp))
                return true;        
            else if (gap == k + 1 && dfs(j, k + 1, stones, dp))
                return true;
            else if (gap > k + 1)
                break;
        }
        return dp[key] = false;
    }
};

int main() {
    Solution s;
    vector<int> stones = {0,1,3,5,6,8,12,17};
    cout << s.canCross(stones) << endl;
    return 0;
}
