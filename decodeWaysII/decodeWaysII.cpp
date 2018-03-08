#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<long> dp(2, 0);
        if (s.length() == 0)
            return 0;
        dp[0] = way1(s[0]);
        if (s.length() == 1)
            return dp[0];
        dp[1] = way1(s[1]) * dp[0] + way2(s[0], s[1]);
        for (int i = 2; i < s.length(); i++) {
            dp[i % 2] = (way1(s[i]) * dp[(i - 1) % 2] + way2(s[i-1], s[i]) * dp[(i - 2) % 2]) % 1000000007;
        }
        return dp[(s.length() - 1) % 2];
    }
    int way1(char c) {
        if (c == '0')
            return 0;
        else if (c >= '1' && c <= '9')
            return 1;
        else if (c == '*')
            return 9;
    }
    int way2(char c1, char c2) {
        if (c1 == '*') {
            if (c2 == '*')
                return 15;
            else if (c2 >= '0' && c2 <= '6')
                return 2;
            else
                return 1;
        } else if (c2 == '*') {
            if (c1 == '1')
                return 9;
            else if (c1 == '2')
                return 6;
            else
                return 0;
        } else {
            int num = (c1 - '0')  * 10 + (c2 - '0');
            if (num >= 10 && num <= 26)
                return 1;
            else
                return 0;
        }
    }
};

int main()
{
  Solution s;
  string ss = "**12";
  cout << s.numDecodings(ss);
  cout << endl;
  return 0;
}
