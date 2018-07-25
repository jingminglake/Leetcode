#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int operation(char op, int n1, int n2) {
        if (op == '+')
            return n2 + n1;
        else if (op == '-')
            return n2 - n1;
        else
            return 0;
    }
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == ' ')
                continue;
            else if (isdigit(c)) {
                while (i < s.length() && isdigit(s[i])) {
                    num = s[i] - '0' + num * 10;
                    i++;
                }
                i--;
                nums.push(num);
                num = 0;
            } else if (c == '(') {
                ops.push(c);
            } else if (c == ')') {
                while (ops.top() != '(') {
                    char op = ops.top(); ops.pop();
                    int n1 = nums.top(); nums.pop();
                    int n2 = nums.top(); nums.pop();
                    nums.push(operation(op, n1, n2));
                }
                ops.pop();
            } else if (c == '+' || c == '-') {
                while (!ops.empty() && ops.top() != '(') {
                    char op = ops.top(); ops.pop();
                    int n1 = nums.top(); nums.pop();
                    int n2 = nums.top(); nums.pop();
                    nums.push(operation(op, n1, n2));
                }
                ops.push(c);
            }
        }
        while (!ops.empty()) {
            char op = ops.top(); ops.pop();
            int n1 = nums.top(); nums.pop();
            int n2 = nums.top(); nums.pop();
            nums.push(operation(op, n1, n2));
        }
        return nums.top();
    }
};

int main() {
    Solution s;
    string str = "(1+(4+5+2)-3)+(6+8)";
    cout << s.calculate(str) << endl;
    return 0;
}
