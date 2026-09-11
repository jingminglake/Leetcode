#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        if (s.length() == 0)
            return s;
        string res;
        stack<string> strStk;
        stack<int> numStk;
        int i = 0;
        while (i < s.length()) {
            if (s[i] == ']') {
                string temp = strStk.top();
                strStk.pop();
                for (int k = 0; k < numStk.top(); k++) {
                    temp += res;
                }
                res = temp;
                numStk.pop();
                i++;
            } else if (isdigit(s[i])) {
                int n = 0;
                while (i < s.length() && isdigit(s[i])) {
                    n = 10 * n + s[i] - '0';
                    i++;
                }
                numStk.push(n);
            } else if (s[i] == '[') {
                strStk.push(res);
                res = "";
                i++;
            } else {
                res += s[i++];
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    string ss = "3[a2[c]]";
    cout << s.decodeString(ss);
    cout << endl;
    return 0;
}
