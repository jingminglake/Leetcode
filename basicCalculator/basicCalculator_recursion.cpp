#include <iostream>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        return helper(s, 0, s.length() - 1);
    }
    int helper(string& s, int start, int end) {
        int res = 0;
        int num = 0;
        int sign = 1;
        for (int i = start; i <= end; i++) {
            if (isdigit(s[i])) {
                num = (s[i] - '0') + num * 10;
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
                num = helper(s, j + 1, i - 1);
            } 
            if (s[i] == '+' || s[i] == '-' || i == end) {
                res += sign * num;
                num = 0;
                sign = (s[i] == '+') ? 1 : -1;
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
