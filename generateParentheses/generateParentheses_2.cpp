#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParentheses(int n) {
        vector<string> ans;
        string path;
        if (n < 1)
            return ans;
        DFS(n, n, path, ans);
        return ans;
    
    }
    void DFS(int left, int right, string& path, vector<string>& ans) {
        if (left == 0 && right == 0) {
            ans.push_back(path);
            return;
        }
        if (left > right)
            return;
        if (left > 0) {
            path.push_back('(');
            DFS(left-1, right, path, ans);
            path.pop_back();
        }
        path.push_back(')');
        DFS(left, right-1, path, ans);
        path.pop_back();
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
