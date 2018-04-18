#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        int n = S.size();
        vector<string> res;
        for (int i = 1; i <= n - 3; i++) {
            vector<string> A = helper(S.substr(1, i));
            vector<string> B = helper(S.substr(i + 1, n - 2 - i));
            for (auto& a : A) {
                for (auto& b : B) {
                    res.push_back("(" + a + ", " + b + ")");
                }
            }
        }
        return res;
    }
    vector<string> helper(string s) {
        vector<string> res;
        int n = s.size();
        if (n == 0 || (n > 1 && s[0] == '0' && s[n - 1] == '0') )
            return res;
        if (n > 1 && s[0] == '0') {
            res.push_back("0." + s.substr(1));
            return res;
        }
        if (n > 1 && s[n - 1] == '0') {
            res.push_back(s);
            return res;
        }
        res.push_back(s);
        for (int i = 1; i < n; i++)
            res.push_back(s.substr(0, i) + "." + s.substr(i));
        return res;
    }
};

int main() {
    Solution s;
    string ss = "(00011)";
    for (string str : s.ambiguousCoordinates(ss))
        cout << str << " ";
    cout << endl;
    return 0;
}
