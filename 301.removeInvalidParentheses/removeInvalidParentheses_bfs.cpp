#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> visited;
        visited.insert(s);
        queue<string> q;
        q.push(s);
        bool found = false;
        while (!q.empty()) {
            string temp = q.front();
            q.pop();
            if (isValid(temp)) {
                res.push_back(temp);
                found = true;
            }
            if (found)
                continue;
            for (int i = 0; i < temp.size(); i++) {
                if (temp[i] != '(' && temp[i] != ')')
                    continue;
                string next = temp.substr(0, i) + temp.substr(i+1);
                if (!visited.count(next)) {
                    q.push(next);
                    visited.insert(next);
                }
            }
        }
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
};

int main()
{
  Solution s;
  for (string ss : s.removeInvalidParentheses(string("()())()")))
    cout << ss << " ";
  cout << endl;
  return 0;
}
