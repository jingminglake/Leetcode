#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int len = s.length();
    bool dp[len][len];
    memset(dp, false, len*len*sizeof(bool));
    int maxLen = 0;
    int left = 0;
    for (int j = 0; j < len; j++) {
      for (int i = 0; i <= j; i++) {
	if (i == j)
	  dp[i][j] = true;
	else if (j - i == 1)
	  dp[i][j] = (s[i] == s[j]);
	else 
	  dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
                
	if (dp[i][j]) {
	  if (maxLen < j - i + 1) {
	    maxLen = j - i + 1;
	    left  = i;
	  }
	}
      }
    }
    return s.substr(left, maxLen);
  }
};


int main()
{
  Solution s;
  string ss = "cbbd";
  cout << s.longestPalindrome(ss) << endl;
  return 0;
}
