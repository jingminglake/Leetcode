#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, res, path, 0);
        return res;
    }
    void dfs(vector<int>& candidates, int target, vector<vector<int> >& res, vector<int>& path, int start) {
        if (target == 0) {
            res.push_back(path);
        }
        for (int i = start; i < candidates.size(); i++) {
            if (target >= candidates[i] && (i == start || candidates[i] != candidates[i - 1])) {
                path.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], res, path, i + 1);
                path.pop_back();
            }
        }
    }
};

int main()
{
    Solution s;
    int a[7] = {10,1,2,7,6,1,5};
    vector<int> vec(a, a+7);
    vector<vector<int> > res = s.combinationSum2(vec, 8);
    for (vector<int> vec : res) {
        for (int i : vec)
            cout << i << " ";
        cout << endl;
    }
    cout << endl;
    return 0;
}
