#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        if (isValid(s)) {
            res.push_back(s);
            return res;
        }
        bfs(s, res);
        return res;
    }
    void bfs(string& s, vector<string>& res) {
        queue<string> q;
        q.push(s);
        unordered_set<string> set;
        set.insert(s);
        bool find = false;
        while (!q.empty()) {
            if (find)
                return;
            int size = q.size();
            for (int k = 0; k < size; k++) {
                string str = q.front();
                q.pop();
                for (int i = 0; i < str.length(); i++) {
                    if (str[i] != '(' && str[i] != ')')
                        continue;
                    string next = str.substr(0, i) + str.substr(i + 1);
                    //cout << next << endl;
                    if (set.count(next))
                        continue;
                    if (isValid(next)) {
                        res.push_back(next);
                        find = true;
                    }
                    q.push(next);
                    set.insert(next);
                }
            }
        }
    }
    bool isValid(string& s) {
        int leftCount = 0;
        for (char c : s) {
            if (leftCount < 0) {
                return false; 
            } else if (c == '(') {
                leftCount++;
            } else if (c == ')') {
                leftCount--;
            }
        }
        return leftCount == 0;
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
