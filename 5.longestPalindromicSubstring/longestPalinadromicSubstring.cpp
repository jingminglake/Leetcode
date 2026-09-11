#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) return s;
        string res;
        int maxLen = 0;
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            extendStr(s, i, i, maxLen, start);
            extendStr(s, i, i + 1, maxLen, start);
        }
        return s.substr(start, maxLen);
    }
    void extendStr(string& s, int mid1, int mid2, int& maxLen, int& start) {
        while (mid1 >= 0 && mid2 <= s.length()) {
            if (s[mid1] != s[mid2]) break;
            if (mid2 - mid1 + 1 > maxLen) {
                maxLen = mid2 - mid1 + 1;
                start = mid1;
            }
            mid1--; mid2++;
        }
    }
};


int main()
{
    Solution s;
    string ss = "cbbd";
    cout << s.longestPalindrome(ss) << endl;
    return 0;
}
