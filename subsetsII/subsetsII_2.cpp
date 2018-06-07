#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        dfs(res, path, nums, 0);
        return res;
    }
    void dfs(vector<vector<int> >& res, vector<int>& path, vector<int>& nums, int start) {
        res.push_back(path);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            path.push_back(nums[i]);
            dfs(res, path, nums, i + 1);
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
