#include <iostream>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res;
        int count = 0;
        string temp;
        for (int i = S.length() - 1; i >= 0; i--) {
            if (isalpha(S[i]))
                temp += toupper(S[i]);
            else if (isdigit(S[i]))
                temp += S[i];
            else
                continue;
            if (++count == K) {
                res += temp + "-";
                temp = "";
                count = 0;
            }
        }
        if (count != 0) {
            res += temp;
        }
        if (res.back() == '-')
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    string S = "2-5g-3-J";
    cout << s.licenseKeyFormatting(S, 2) << endl;
    return 0;
}
