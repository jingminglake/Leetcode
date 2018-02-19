#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0)
            return 0;
        vector<int> dp(s.length(), 0);
        dp[0] = (s[0] == '0') ? 0 : 1;
        if (s.length() == 1) {
            return dp[0];
        }
        int num = stoi(s.substr(0, 2));
        if (s[1] != '0')
            dp[1] = dp[0];
        if (num >= 10 && num <= 26)
            dp[1]++;
        for (int i = 2; i < s.size(); i++) {
            if (s[i] != '0')
                dp[i] = dp[i - 1];
            int num = stoi(s.substr(i - 1, 2));
            if (num >= 10 && num <= 26)
                dp[i] += dp[i - 2];
        }
        return dp[s.length() - 1]; 
    }
};

int main()
{
  Solution s;
  string ss = "27";
  cout << s.numDecodings(ss);
  cout << endl;
  return 0;
}
