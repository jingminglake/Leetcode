#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int left = 0, right = 0;
        for (char c : s) {
            if (c == '(')
                left++;
            else if (c == ')'){
                if (left == 0)
                    right++;
                else
                    left--;
            }
        }
        dfs(s, 0, left, right, res);
        return res;
    }
    bool isValid(string t) {
        int n = 0;
        for (char c : t) {
            if (c == '(')
                n++;
            else if (c == ')' && --n < 0)
                return false;
        }
        return n == 0;
    }
    void dfs(string s, int start, int left, int right, vector<string>& res) {
        if (left == 0 && right == 0 && isValid(s)) {
            res.push_back(s);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (i != start && s[i] == s[i - 1])
                continue;
            if (right > 0 && s[i] == ')')
                dfs (s.substr(0, i) + s.substr(i + 1), i, left, right - 1, res);
            if (left > 0 && s[i] == '(')
                dfs (s.substr(0, i) + s.substr(i + 1), i, left - 1, right, res);
        }
    }
};

int main()
{
  Solution s;
  for (string ss : s.removeInvalidParentheses(string("()())()")))
    cout << ss << " ";
  cout << endl;
  return 0;
}
