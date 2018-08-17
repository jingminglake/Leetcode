#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> res;
        for (int i = 1; i < (int)S.length() - 2; i++) {
            vector<string> left_res = helper(S.substr(1, i));
            vector<string> right_res = helper(S.substr(i + 1, S.length() - 2 - i));
            for (string& left_s : left_res) {
                for (string& right_s : right_res) {
                    res.push_back("(" + left_s + ", " + right_s + ")");
                }
            }
        }
        return res;
    }
    vector<string> helper(string S) {
        vector<string> res;
        int n = S.length();
        if (n == 0 ||(n > 1 && S[0] == '0' && S[n - 1] == '0')) {
            return res;
        }
        if (n > 1 && S[0] == '0') {
            res.push_back("0." + S.substr(1));
            return res;
        }
        if (n > 1 && S[n - 1] == '0') {
            res.push_back(S);
            return res;
        }
        res.push_back(S);
        for (int i = 0; i < n - 1; i++) {
            res.push_back(S.substr(0, i + 1) + "." + S.substr(i + 1));
        }
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
