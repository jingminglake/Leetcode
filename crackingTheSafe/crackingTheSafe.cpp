#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string crackSafe(int n, int k) {
        int total_size = pow(k, n);
        string res(n, '0');
        unordered_set<string> visited{res};
        if (dfs(res, total_size, n, k, visited))
            return res;
        return "";
    }
    bool dfs (string& res, int total_size, int n, int k, unordered_set<string>& visited) {
        if (visited.size() == total_size)
            return true;
        string node = res.substr(res.length() - n + 1, n - 1);
        for (char c = '0'; c < '0' + k; c++) {
            node.push_back(c);
            if (!visited.count(node)) {
                res.push_back(c);
                visited.insert(node);
                if (dfs(res, total_size, n, k, visited))
                    return true;
                visited.erase(node);
                res.pop_back();
            }
            node.pop_back();
        }
        return false;
    }
};

int main()
{
    Solution s;
    int n = 2, k = 2;
    cout << s.crackSafe(n, k);
    cout << endl;
    return 0;
}
