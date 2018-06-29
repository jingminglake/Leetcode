#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        unordered_map<string, int> m;
        string visited(nums.size(), '0');
        return dfs (nums, m, visited);
    }
    int dfs (vector<int>& nums, unordered_map<string, int>& m, string& visited) {
        if (m.count(visited))
            return m[visited];
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] == '1')
                continue;
            pair<int, int> p = findLeftAndRightAdjancent(nums, visited, i);
            visited[i] = '1';
            res = max (res, p.first * nums[i] * p.second + dfs(nums, m, visited));
            visited[i] = '0';
        }
        return m[visited] = res;
    }
    pair<int, int> findLeftAndRightAdjancent(vector<int>& nums, string& visited, int index) {
        pair<int, int> res = {1, 1};
        for (int i = index - 1; i >= 0; i--) {
            if (visited[i] == '0') {
                res.first = nums[i];
                break;
            }
        }
        for (int i = index + 1; i < nums.size(); i++) {
            if (visited[i] == '0') {
                res.second = nums[i];
                break;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,1,5,8};
    cout << s.maxCoins(nums) << endl;
    return 0;
}
