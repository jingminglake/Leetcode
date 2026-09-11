#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        vector<bool> visited(nums.size(), false);
        vector<int> path;
        dfs(nums, res, visited, path, 0);
        return res;
    }
    void dfs(vector<int>& nums, vector<vector<int> >& res, vector<bool>& visited, vector<int>& path, int index) {
        if (index == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                path.push_back(nums[i]);
                cout << "i: " << i << " index: " << index + 1 << endl;
                for (int i : path) cout << i;
                cout << endl;
                dfs(nums, res, visited, path, index + 1);
                path.pop_back();
                visited[i] = false;
            }
        }
    }
};

int main()
{
    Solution s;
    int a[3] = {1,2,3};
    vector<int> vec(a, a+3);
    vector<vector<int> > res = s.permute(vec);
    vector<vector<int> >::iterator it = res.begin();
    while (it != res.end()) {
        for (int i : *it)
            cout << i << " ";
        cout << endl;
        ++it;
    }
    return 0;
}
