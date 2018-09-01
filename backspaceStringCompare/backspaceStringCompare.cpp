#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s1, s2;
        for (char c : S) {
            if (c == '#') {
                if (!s1.empty())
                    s1.pop();
            } else {
                s1.push(c);
            }
        }
        for (char c : T) {
            if (c == '#') {
                if (!s2.empty())
                    s2.pop();
            } else {
                s2.push(c);
            }
        }
        return s1 == s2;
    }
};

int main() {
    Solution s;
    string S = "a##c", T = "#a#c";
    cout << s.backspaceCompare(S, T) << endl;
    return 0;
}
