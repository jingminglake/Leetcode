#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int operation(char op, int num1, int num2) {
        switch (op) {
            case '+': return num1 + num2;
            case '-': return num1 - num2;
            case '*': return num1 * num2;
            case '/': return num1 / num2; // assume num2 is not 0
        }
        return 0;
    }
    bool precedence(char op1, char op2) {
        if (op2 == '(' || op2 == ')')
            return false;
        if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'))
            return false;
        return true;
    }
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ')
                continue;
            if (isdigit(s[i])) {
                while (i < s.length() && isdigit(s[i])) {
                    num = s[i] - '0' + num * 10;
                    i++;
                }
                i--;
                nums.push(num);
                num = 0;
            } else if (s[i] == '(') {
                ops.push(s[i]);
            } else if (s[i] == ')') {
                // do the math when we encounter a ')' until '('
                while (ops.top() != '(') {
                    char op = ops.top(); ops.pop();
                    int num1 = nums.top(); nums.pop();
                    int num2 = nums.top(); nums.pop();
                    nums.push(operation(op, num2, num1));
                }
                ops.pop(); // pop '('
            } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                while (!ops.empty() && precedence(s[i], ops.top())) {
                    char op = ops.top(); ops.pop();
                    int num1 = nums.top(); nums.pop();
                    int num2 = nums.top(); nums.pop();
                    nums.push(operation(op, num2, num1));
                }
                ops.push(s[i]);
            }
        }// for
        while (!ops.empty()) {
            char op = ops.top(); ops.pop();
            int num1 = nums.top(); nums.pop();
            int num2 = nums.top(); nums.pop();
            nums.push(operation(op, num2, num1));
        }
        return nums.top();
    }
};

int main()
{
    Solution s;
    string ss = "(2+6* 3+5- (3*14/7+2)*5)+3 ";
    cout << s.calculate(ss);
    cout << endl;
    return 0;
}
