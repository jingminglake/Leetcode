#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> path;
        dfs(nums, path, 0, res);
        return res;
    }
    void dfs(vector<int>& nums, vector<int>& path, int start, vector<vector<int> >& res) {
        if (start == nums.size()) {
            res.push_back(path);
            return;
        }
        dfs (nums, path, start + 1, res);
        path.push_back(nums[start]);
        dfs (nums, path, start + 1, res);
        path.pop_back();
    }
};

int main()
{
    Solution s;
    int a[3] = {1,2,3};
    vector<int> vec(a, a+3);
    vector<vector<int> > res = s.subsets(vec);
    vector<vector<int> >::iterator it = res.begin();
    while (it != res.end()) {
        for (int i : *it)
            cout << i << " ";
        cout << endl;
        ++it;
    }
    return 0;
}
