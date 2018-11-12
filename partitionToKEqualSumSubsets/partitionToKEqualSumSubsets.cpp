#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int n : nums)
            sum += n;
        if (sum % k != 0)
            return false;
        string visited(nums.size(), '0');
        unordered_map<int, unordered_map<string, bool> > dp;
        return dfs(nums, sum / k, k, visited, dp, 0);
    }
    bool dfs(vector<int>& nums, int target, int k, string visited, unordered_map<int, unordered_map<string, bool> >& dp, int path) {
        if (k == 0)
            return dp[k][visited] = true;
        if (dp.count(k) && dp[k].count(visited))
            return dp[k][visited];
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] == '0') {
                path += nums[i];
                string next_visited = visited;
                //cout << visited << " ==== " << k << endl;
                next_visited[i] = '1';
                if (path > target) {
                    path -= nums[i];
                    continue;
                }
                if (path == target)
                    return dfs (nums, target, k - 1, next_visited, dp, 0);
                if (dfs (nums, target, k, next_visited, dp, path))
                    return dp[k][next_visited] = true;
                else
                    path -= nums[i];
            }
        }
        return dp[k][visited] = false;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4,3,2,3,5,2,1};
    int k = 4;
    cout << s.canPartitionKSubsets(nums, k) << endl;
    return 0;
}
