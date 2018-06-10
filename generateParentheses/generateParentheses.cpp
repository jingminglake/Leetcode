#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParentheses(int n) {
        vector<string> res;
        if (n < 1)
            return res;
        dfs(n, n, "", res);
        return res;
    }
    void dfs (int left, int right, string path, vector<string>& res) {
        if (left == 0 && right == 0) {
            res.push_back(path);
            return;
        }
        if (left > right || left < 0 || right < 0)
            return;
        dfs (left - 1, right, path + "(", res);
        dfs (left, right - 1, path + ")", res);
    }
};

int main()
{
    Solution s;
    vector<string> vec = s.generateParentheses(3);
    vector<string>::iterator it = vec.begin();
    while (it != vec.end()) {
        cout << *it << endl;
        ++it;
    }
    return 0;
}
