#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> m;
        m.insert({')', '('});
        m.insert({'}', '{'});
        m.insert({']', '['});
        stack<char> stk;
        for (char c : s) {
            if (c == ')' || c == '}' || c == ']') {
                if (stk.empty() || stk.top() != m[c]) return false;
                else stk.pop();
            } else {
                stk.push(c);
            }
        }
        return stk.empty();
    }
};

int main()
{
    Solution s;
    cout << s.isValid(string("{}{}{}{}[][]")) << endl;
    return 0;
}
