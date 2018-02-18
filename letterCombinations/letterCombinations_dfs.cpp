#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size() == 0)
            return res;
        vector<string> digit2letter = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string path;
        dfs(digits, digit2letter, path, res, 0);
        return res;
    }
    void dfs(string& digits, vector<string>& digit2letter, string& path, vector<string>& res, int start) {
        if (start == digits.length()) {
            res.push_back(path);
            return;
        }
        string letters = digit2letter[digits[start] - '0'];
        for (int i = 0; i < letters.size(); i++) {
            path += letters[i];
            dfs(digits, digit2letter, path, res, start + 1);
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
