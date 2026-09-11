#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int res = 0;
        if (s.length() == 0)
            return res;
        stack<int> stk;
        int num = 0;
        char sign = '+';
        s += '+';
        for (int i = 0, left = 0; i < s.length(); i++) {
            char c = s[i];
            if ((c >= '0' && c <= '9') || c == ' ') {
                continue;
            }
            num = stoi(s.substr(left, i - left));
            if (sign == '-') {
                stk.push(-num);
            } else if (sign == '+') {
                stk.push(num);
            } else if (sign == '*') {
                int temp = stk.top() * num;
                stk.pop();
                stk.push(temp);
            } else if (sign == '/') {
                int temp = stk.top()  / num;
                stk.pop();
                stk.push(temp);
            }
            sign = s[i];
            left = i + 1;
        }
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
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
