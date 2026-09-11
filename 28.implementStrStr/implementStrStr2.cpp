#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack == needle) return 0;
        for (int i = 0; i <= (int)haystack.size() - (int)needle.size(); i++) {
            if (haystack.substr(i, needle.size()) == needle) return i;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    string haystack = "babcabceabcabcabcaaa";
    string needle = "abcabcaaa";
    cout << s.strStr(haystack, needle) << endl;
    return 0;
}
