#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        vector<int> path;
        vector<int> visited(nums.size(), false);
        dfs(nums, 0, path, res, visited);
        return res;
    }
    void dfs(vector<int>& nums, int level, vector<int>& path, vector<vector<int> >& res, vector<int>& visited) {
        if (level == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;
                path.push_back(nums[i]);
                visited[i] = true;
                dfs(nums, level + 1, path, res, visited);
                path.pop_back();
                visited[i] = false;
            }
        }
    }
};

int main()
{
    Solution s;
    int a[4] = {1,2,1,2};
    vector<int> vec(a, a+4);
    vector<vector<int> > res = s.permuteUnique(vec);
    vector<vector<int> >::iterator it = res.begin();
    while (it != res.end()) {
        for (int i : *it)
            cout << i << " ";
        cout << endl;
        ++it;
    }
    return 0;
}
