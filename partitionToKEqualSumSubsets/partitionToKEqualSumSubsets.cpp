#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (nums.size() == 0) return false;
        int total = 0;
        for (int n : nums) total += n;
        if (total % k != 0) return false;
        string visited(nums.size(), '0');
        unordered_map<int, unordered_map<string, bool> > m;
        int target = total / k;
        return dfs(nums, k, visited, target, target, m);
    }
    bool dfs(vector<int>& nums, int k, string& visited, int target, int remain, unordered_map<int, unordered_map<string, bool> >& m) {
        if (m.count(k) && m[k].count(visited)) return m[k][visited];
        if (k == 1 && remain == 0) return m[k][visited] = true;
        if (k > 1 && remain == 0) {
            k--;
            remain = target;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (remain >= nums[i] && visited[i] != '1') {
                visited[i] = '1';
                m[k][visited] = dfs(nums, k, visited, target, remain - nums[i], m);
                if (m[k][visited]) return true;
                visited[i] = '0';
            }
        }
        return m[k][visited] = false;
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
