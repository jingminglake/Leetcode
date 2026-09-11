#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> path;
        dfs(candidates, target, path, res, 0);
        return res;
    }
    void dfs(vector<int>& candidates, int target, vector<int>& path, vector<vector<int> >& res, int start) {
        if (target == 0) {
            res.push_back(path);
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] <= target) {
                path.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], path, res, i);
                path.pop_back();
            }
        }
    }
};

int main()
{
    Solution s;
    int a[4] = {2,3,6,7};
    vector<int> vec(a, a+4);
    vector<vector<int> > res = s.combinationSum(vec, 7);
    for (vector<int> vec : res) {
        for (int i : vec)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
