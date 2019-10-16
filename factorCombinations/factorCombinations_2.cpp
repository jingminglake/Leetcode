#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int> > res;
        vector<int> path;
        dfs(n, 2, path, res);
        return res;
    }
    void dfs(int n, int start, vector<int>& path, vector<vector<int> >& res) {
        for (int i = start; i * i <= n; i++) {
            if (n % i == 0) {
                int remain = n / i;
                path.push_back(i);
                path.push_back(remain);
                res.push_back(path);
                path.pop_back();
                dfs(remain, i, path, res);
                path.pop_back();
            }
        }
    }
};

int main()
{
    Solution s;
    for (vector<int>& res : s.getFactors(32)) {
        for (int vec : res)
            cout << vec << " ";
        cout << endl;
    }
    return 0;
}
