#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        if (len < 2) return false;
        for (int i = len / 2; i >= 1; i--) {
            if (len % i == 0) {
                string pattern = s.substr(0, i);
                if (canConstruct(s, pattern)) return true;
            }
        }
        return false;
    }
    bool canConstruct(string& s, string& pattern) {
        int len = pattern.length();
        for (int i = len; i < s.length(); i++) {
            if (s[i] != pattern[i % len]) return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    string str = "bab";
    cout << s.repeatedSubstringPattern(str) << endl;
    return 0;
}
