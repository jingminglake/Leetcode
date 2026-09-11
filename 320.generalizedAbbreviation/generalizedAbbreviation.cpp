#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        dfs (word, 0, "", 0, res);
        return res;
    }
    void dfs (string& word, int index, string path, int cnt, vector<string>& res) {
        if (index == word.length()) {
            path += (cnt > 0 ? to_string(cnt) : "");
            res.push_back(path);
            return;
        }
        dfs (word, index + 1, path, cnt + 1, res);
        dfs (word, index + 1, path + (cnt > 0 ? to_string(cnt) : "") + word[index], 0, res);
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
