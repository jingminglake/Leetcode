#include <iostream>
using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int len_s = s.length(), len_t = t.length();
        if (abs(len_s - len_t) > 1)
            return false;
        for (int i = 0; i < min (len_s, len_t); i++) {
            if (s[i] != t[i]) {
                if (len_s > len_t) {
                    return s.substr(i + 1) == t.substr(i);
                } else if (len_s < len_t) {
                    return s.substr(i) == t.substr(i + 1);
                } else {
                    return s.substr(i + 1) == t.substr(i + 1);
                }
            }
        }
        return len_s != len_t;
    }
};

int main()
{
    Solution s;
    string ss = "ab";
    string tt = "abc";
    cout << s.isOneEditDistance(ss, tt) << endl;
    return 0;
}
