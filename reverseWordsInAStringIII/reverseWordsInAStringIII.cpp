#include <iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            if ((i - 1 < 0 || s[i - 1] == ' ') && s[i] != ' ') {
                start = i;
            } else if (s[i] != ' ' && (i + 1 == s.length() || s[i + 1] == ' ')) {
                reverse(s, start, i);
            }
        }
        return s;
    }
    
    void reverse(string& s, int start, int end) {
        while (start < end) {
            char c = s[start];
            s[start] = s[end];
            s[end] = c;
            start++; end--;
        }
    }
};

int main()
{
    Solution s;
    string str = "hello world";
    cout << s.reverseWords(str) << endl;
    return 0;
}
