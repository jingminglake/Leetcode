#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canWin(string s) {
        if (s.length() == 0)
            return false;
        unordered_map<string, bool> m;
        return helper(s, m);
    }
    bool helper(string s, unordered_map<string, bool>& m) {
        if (m.count(s))
            return m[s];
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == '+' && s[i + 1] == '+') {
                string opponent = s.substr(0, i) + "--" + s.substr(i + 2);
                if (!helper(opponent, m)) {
                    return m[s] = true;
                }
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
