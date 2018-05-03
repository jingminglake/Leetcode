#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int res = 0;
        int sign = 1;
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                int num = s[i] - '0';
                while (i + 1 < s.length() && isdigit(s[i + 1])) {
                    num = num * 10 + s[i + 1] - '0';
                    i++;
                }
                res += sign * num;
            } else if (s[i] == '+') {
                sign = 1;
            } else if (s[i] == '-') {
                sign = -1;
            } else if (s[i] == '(') {
                stk.push(res);
                stk.push(sign);
                res = 0;
                sign = 1;
            } else if (s[i] == ')') {
                res *= stk.top();
                stk.pop();
                res += stk.top();
                stk.pop();
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    string str = "(1+(4+5+2)-3)+(6+8)";
    cout << s.calculate(str) << endl;
    return 0;
}
