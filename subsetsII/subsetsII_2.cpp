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
    void dfs(vector<int>& nums, int start, vector<int>& path, vector<vector<int> >& res) {
        res.push_back(path);
        for (int i = start; i < nums.size(); i++) {
            if (i != start && nums[i] == nums[i - 1])
                continue;
            path.push_back(nums[i]);
            dfs(nums, i + 1, path, res);
            path.pop_back();
        }
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
