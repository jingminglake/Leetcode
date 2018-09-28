#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int num : nums)
            sum += num;
        if (sum % k != 0)
            return false;
        string visited(nums.size(), '0');
        unordered_map<int, unordered_map<string, bool> > m;
        return dfs(nums, k, sum / k, 0, 0, visited, m);
    }
    bool dfs(vector<int>& nums, int k, int target, int curSum, int start, string& visited, unordered_map<int, unordered_map<string, bool> >& m) {
        if (m.count(k) && m[k].count(visited)) {
            return m[k][visited];
        }
        if (k == 0)
            return m[k][visited] = true;
        if (curSum == target)
            return dfs(nums, k - 1, target, 0, 0, visited, m);
        for (int i = start; i < nums.size(); i++) {
            if (visited[i] == '0') {
                visited[i] = '1';
                if (dfs(nums, k, target, curSum + nums[i], i, visited, m))
                    return m[k][visited] = true;
                visited[i] = '0';
            }
        }
        return false;
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
