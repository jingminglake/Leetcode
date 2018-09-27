#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.length() == 0)
            return res;
        vector<string> vec = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string path;
        dfs(digits, res, path, vec, 0);
        return res;
    }
    void dfs(string& digits, vector<string>& res, string& path, vector<string>& vec, int index) {
        if (index == digits.size()) {
            res.push_back(path);
            return;
        }
        for (char c : vec[digits[index] - '0']) {
            path.push_back(c);
            dfs(digits, res, path, vec, index + 1);
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
