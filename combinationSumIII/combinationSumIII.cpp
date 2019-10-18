#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int> path;
        dfs(k, n, res, path, 1);
        return res;
    }
    void dfs(int k, int n, vector<vector<int> >& res, vector<int>& path, int start) {
        if (k == 0 && n == 0) {
            res.push_back(path);
        }
        for (int i = start; i <= 9; i++) {
            if (n >= i) {
                path.push_back(i);
                dfs(k - 1, n - i, res, path, i + 1);
                path.pop_back();
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int> > res = s.combinationSum3(3, 7);
    for (vector<int> vec : res) {
        for (int i : vec)
            cout << i << " ";
        cout << endl;
    }
    cout << endl;
    return 0;
}
