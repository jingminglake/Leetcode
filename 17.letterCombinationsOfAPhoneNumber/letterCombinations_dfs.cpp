#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.length() == 0) return res;
        string path;
        vector<string> digit2letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        dfs(digits, 0, path, res, digit2letters);
        return res;
    }
    void dfs(string digits, int level, string& path, vector<string>& res, vector<string>& digit2letters) {
        if (level == digits.length()) {
            res.push_back(path);
            return;
        }
        for (char c : digit2letters[digits[level] - '0']) {
            path.push_back(c);
            dfs(digits, level + 1, path, res, digit2letters);
            path.pop_back();
        }
    }
};

int main()
{
    Solution s;
    vector<string> ans = s.letterCombinations(string("234"));
    vector<string>::iterator it = ans.begin();
    while(it != ans.end()){
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    return 0;
}
