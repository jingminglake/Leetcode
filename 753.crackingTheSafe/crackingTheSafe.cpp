#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string crackSafe(int n, int k) {
        int nodes = pow(k, n);
        string res = string(n, '0');
        unordered_set<string> visited{res};
        if (dfs(res, nodes, n, k, visited))
            return res;
        return "";
    }
    bool dfs(string& res, int nodes, int n, int k, unordered_set<string>& visited) {
        if (visited.size() == nodes) {
            return true;
        }
        string node_next = res.substr(res.length() - n + 1);
        for (char i = 0; i < k; i++) {
            node_next += (char)(i + '0');
            if (!visited.count(node_next)) {
                res += (char)(i + '0');
                visited.insert(node_next);
                if(dfs(res, nodes, n, k, visited))
                    return true;
                visited.erase(node_next);
                res.pop_back();
            }
            node_next.pop_back();
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
