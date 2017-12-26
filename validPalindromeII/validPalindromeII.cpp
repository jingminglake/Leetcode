#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  bool validPalindrome(string s) {
    int i = 0, j = s.length() - 1;
    while (i < j && s[i] == s[j]) {
      i++;
      j--;
    }
    if (i >= j)
      return true;
    if (isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1))
      return true;
    return false;
  }
  bool isPalindrome(string s, int i, int j) {
    while (i < j) {
      if (s[i] == s[j]) {
	i++;
        j--;
      } else
	return false;
    }
    return true;
  }
};

int main()
{
  Solution s;
  string ss = "aba";
  string ss1 = "abca";
  cout << s.validPalindrome(ss) << endl;
  cout << s.validPalindrome(ss1) << endl;
  return 0;
}
