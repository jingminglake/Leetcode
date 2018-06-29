#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canWin(string s) {
        if (s.length() < 2)
            return false;
        unordered_map<string, bool> m;
        return dfs(s, m);
    }
    bool dfs(string s, unordered_map<string, bool>& m) {
        if (m.count(s))
            return m[s];
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == '+' && s[i + 1] == '+') {
                string next_s = s;
                next_s[i] = next_s[i + 1] = '-';
                if (!dfs(next_s, m))
                    return m[s] = true;
            }
        }
        return m[s] = false;
    }
};

int main() {
    Solution s;
    cout << s.canWin("++-++-++") << endl;
    return 0;
}
