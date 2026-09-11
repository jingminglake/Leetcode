#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int leftP = n, rightP = n;
        vector<string> res;
        string path;
        dfs(n, n, path, res);
        return res;
    }
    void dfs(int leftP, int rightP, string& path, vector<string>& res) {
        if (leftP == 0 && rightP == 0) {
            res.push_back(path);
            return;
        }
        if (leftP < 0 || rightP < 0 || leftP > rightP)
            return;
        path += "(";
        dfs (leftP - 1, rightP, path, res);
        path.pop_back();
        path += ")";
        dfs (leftP, rightP - 1, path, res);
        path.pop_back();
    }
};

int main()
{
    Solution s;
    vector<string> vec = s.generateParenthesis(3);
    vector<string>::iterator it = vec.begin();
    while (it != vec.end()) {
        cout << *it << endl;
        ++it;
    }
    return 0;
}
