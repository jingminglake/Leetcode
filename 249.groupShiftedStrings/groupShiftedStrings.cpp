#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string> > res;
        unordered_map<string, vector<string> > m;
        for (string s : strings) {
            if (s.empty())
                continue;
            int offset = s[0] - 'a';
            string key;
            for (int i = 0; i < s.length(); i++) {
                char c = s[i] - offset;
                if (c < 'a')
                    c += 26;
                key += c;
            }
            m[key].push_back(s);
        }
        for (auto& p : m)
            res.push_back(p.second);
        return res;
    }
};

int main () {
    Solution s;
    vector<string> ss = {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
    for (auto& vec : s.groupStrings(ss)) {
        for (string& str : vec)
            cout << str << " ";
        cout << endl;
    }
    return 0;
}
