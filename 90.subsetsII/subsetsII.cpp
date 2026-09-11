#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        vector<int> path;
        dfs(nums, 0, path, res);
        return res;
    }
    void dfs(vector<int>& nums, int level, vector<int>& path, vector<vector<int> >& res) {
        if (level == nums.size()) {
            res.push_back(path);
            return;
        }
        int next_level = level + 1;
        while (next_level < nums.size() && nums[next_level] == nums[next_level - 1])
            next_level++;
        dfs(nums, next_level, path, res);
        path.push_back(nums[level]);
        dfs(nums, level + 1, path, res);
        path.pop_back();
    }
};

int main()
{
    Solution s;
    int a[3] = {1,2,2};
    vector<int> vec(a, a+3);
    vector<vector<int> > res = s.subsetsWithDup(vec);
    vector<vector<int> >::iterator it = res.begin();
    while (it != res.end()) {
        for (int i : *it)
            cout << i << " ";
        cout << endl;
        ++it;
    }
    return 0;
}
