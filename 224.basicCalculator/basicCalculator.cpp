#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int res = 0;
        stack<int> stk;
        int i = 0;
        int sign = 1;
        while (i < s.length()) {
            if (isdigit(s[i])) {
                int num = 0;
                while (i < s.length() && isdigit(s[i])) {
                    num = (s[i] - '0') + num * 10;
                    i++;
                }
                i--;
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
            i++;
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
