#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        if (s.length() == 0)
            return s;
        string res;
        int i = 0;
        while (i < s.length()) {
            if (isdigit(s[i])) {
                int n = 0;
                while (i < s.length() && isdigit(s[i])) {
                    n = 10 * n + s[i] - '0';
                    i++;
                }
                int j = i, cnt = 0;
                while (i < s.length()) {
                    if (s[i] == '[') cnt++;
                    else if (s[i] == ']') cnt--;
                    if (cnt == 0) break;
                    i++;
                }
                string temp = decodeString(s.substr(j + 1, i - j - 1));
                while (n--) {
                    res += temp;
                }
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
