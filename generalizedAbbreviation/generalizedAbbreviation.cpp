#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        dfs(word, 0, 0, "", res);
        return res;
    }
    void dfs (string& word, int pos, int cnt, string pre, vector<string>& res) {
        if (pos == word.size()) {
            if (cnt > 0)
                pre += to_string(cnt);
            res.push_back(pre);
            return;
        }
        dfs (word, pos + 1, cnt + 1, pre, res);
        dfs (word, pos + 1, 0, pre + (cnt > 0 ? to_string(cnt) : "") + word[pos], res);
    }
};

int main() {
    Solution s;
    string ss = "word";
    for(string& v : s.generateAbbreviations(ss))
        cout << v << " ";
    cout << endl;
    return 0;
}
