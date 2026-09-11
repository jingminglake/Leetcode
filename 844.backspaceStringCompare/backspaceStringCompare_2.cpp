#include <iostream>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1; // i, j = -1 is ok
        while (1) {
            i = getLastValidIndex(S, i);
            j = getLastValidIndex(T, j);
            //cout << i << " " << j << endl;
            if (i >= 0 && j >= 0 && S[i] == T[j]) {
                i--; j--;
            } else {
                return i == -1 && j == -1;
            }
        }
    }
    int getLastValidIndex(string s, int last) {
        int count = 0;
        int i = last;
        while (i >= 0) {
            if (s[i] == '#') {
                count++;
            } else {
                if (count > 0) {
                    count--;
                } else if (count == 0) {
                    break;
                }
            }
            i--;
        }
        return i;
    }
};

int main() {
    Solution s;
    string S = "a##c", T = "#a#c";
    cout << s.backspaceCompare(S, T) << endl;
    return 0;
}
