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
        int target = total / k;
        return dfs(nums, k, visited, target, target, 0);
    }
    bool dfs(vector<int>& nums, int k, string& visited, int target, int remain, int start) {
        if (k == 1 && remain == 0) return true;
        if (k > 1 && remain == 0) {
            return dfs(nums, k - 1, visited, target, target, 0);
        }
        for (int i = start; i < nums.size(); i++) {
            if (remain >= nums[i] && visited[i] != '1') {
                visited[i] = '1';
                if (dfs(nums, k, visited, target, remain - nums[i], i + 1)) return true;
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
