// clang++ partitionEqualSubsetSum_dfs_mem.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2 != 0) return false;
        sum /= 2;
        int preSum = 0;
        unordered_set<string> visited;
        return dfs(0, nums, preSum, sum, visited);
    }
    
    bool dfs(int level, vector<int>& nums, int& preSum, int target, unordered_set<string>& visited) {
        if (preSum == target) {
            return true;
        }
        if (visited.count(to_string(level) + "-" + to_string(preSum))) return false;
        for (int i = level; i < nums.size(); i++) {
            if (nums[i] + preSum > target) continue;
            preSum += nums[i];
            if (dfs(i + 1, nums, preSum, target, visited)) {
                return true;
            }
            preSum -= nums[i];
        }
        visited.insert(to_string(level) + "-" + to_string(preSum));
        return false;
    } 
};

int main()
{
    Solution s;
    vector<int> nums1 = {1,5,11,5};
    vector<int> nums2 = {1,2,3,5};
    cout << s.canPartition(nums1) << endl;
    cout << s.canPartition(nums2) << endl;
    return 0;
}
