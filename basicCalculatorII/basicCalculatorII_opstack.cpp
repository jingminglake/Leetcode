#include <iostream>
#include <vector>
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
        if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'))
            return false;
        return true;
    }
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') continue;
            if (isdigit(s[i])) {
                while (i < s.length() && isdigit(s[i])) {
                    num = s[i] - '0' + num * 10;
                    i++;
                }
                i--;
                nums.push(num);
                num = 0;
            } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                while (!ops.empty() && precedence(s[i], ops.top())) {
                    char op = ops.top(); ops.pop();
                    int num2 = nums.top(); nums.pop();
                    int num1 = nums.top(); nums.pop();
                    nums.push(operation(op, num1, num2));
                }
                ops.push(s[i]);
            }
        }// for
        while (!ops.empty()) {
            char op = ops.top(); ops.pop();
            int num2 = nums.top(); nums.pop();
            int num1 = nums.top(); nums.pop();
            nums.push(operation(op, num1, num2));
        }
        return nums.top();
    }
};

int main()
{
    Solution s;
    string ss = " 3+5 / 2 ";
    cout << s.calculate(ss);
    cout << endl;
    return 0;
}
