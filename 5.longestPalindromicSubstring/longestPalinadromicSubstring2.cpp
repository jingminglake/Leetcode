#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    if (s.length() < 2)
      return s;
    int maxLen = 0;
    int start = 0;
    for (int i = 0; i < s.length(); i++) {
      longestPalindromeHelper(s, i, i, maxLen, start);
      longestPalindromeHelper(s, i, i + 1, maxLen, start);
    }
    return s.substr(start, maxLen);
  }
  void longestPalindromeHelper(string s, int mid1, int mid2, int& maxLen, int& start) {
    while (mid1 >= 0 && mid2 < s.length()) {
      if (s[mid1] != s[mid2])
	break;
      if (mid2 - mid1 + 1 > maxLen) {
	maxLen = mid2 - mid1 + 1;
	start = mid1;
      }
      mid1--;
      mid2++;
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
