// clang++ isSubsequence.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len_s = s.length(), len_t = t.length();
        int p_s = 0, p_t = 0;
        while (p_t < len_t) {
            if (s[p_s] == t[p_t]) {
                p_s++; p_t++;
            } else {
                p_t++;
            }
        }
        return p_s == len_s;
    }
};

int main()
{
    Solution s;
    string s1 = "abc";
    string s2 = "ahbgdc";
    cout << s.isSubsequence(s1, s2) << endl;
    return 0;
}
