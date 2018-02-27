#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
  bool canPermutePalindrome(string s) {
    if (s.length() == 0)
      return false;
    unordered_set<char> charSet;
    for (char c : s) {
      if (!charSet.count(c))
	charSet.insert(c);
      else
	charSet.erase(c);
    }
    return charSet.size() <= 1;
  }
};

int main()
{
  Solution s;
  string ss1 = "code";
  string ss2 = "aab";
  string ss3 = "code";
  cout << s.canPermutePalindrome(ss1) << endl;
  cout << s.canPermutePalindrome(ss2) << endl;
  cout << s.canPermutePalindrome(ss3) << endl;
  return 0;
}
