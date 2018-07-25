#include <iostream>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int res = 0;
        char op = '+';
        int num = 0, tempRes = 0;
        for(int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                num = s[i] - '0' + num * 10;
            } else if (s[i] == '(') {
                int j = i, cnt = 0;
                while (i < s.length()) {
                    if (s[i] == '(')
                        cnt++;
                    else if (s[i] == ')')
                        cnt--;
                    if (cnt == 0)
                        break;
                    i++;
                }
                num = calculate(s.substr(j + 1, i - j - 1));
            }
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
    string ss = "(2+6* 3+5- (3*14/7+2)*5)+3 ";
    cout << s.calculate(ss);
    cout << endl;
    return 0;
}
