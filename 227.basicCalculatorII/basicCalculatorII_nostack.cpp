#include <iostream>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int res = 0;
        char op = '+';
        int num = 0, tempRes = 0;
        for(int i = 0; i < s.length(); i++) {
            if (isdigit(s[i]))
                num = s[i] - '0' + num * 10;
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i == s.length() - 1) {
                switch (op) {
                case '+': tempRes += num; break;
                case '-': tempRes -= num; break;
                case '*': tempRes *= num; break;
                case '/': tempRes /= num; break; // should handle num == 0
                }
                if (s[i] == '+' || s[i] == '-' || i == s.length() - 1) {
                    res += tempRes;
                    tempRes = 0;
                }
                op = s[i];
                num = 0;
            }
        }// for
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
