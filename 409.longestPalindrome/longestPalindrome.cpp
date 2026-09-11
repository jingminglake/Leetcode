#include <iostream>
#include <unordered_map>
using namespace std;

class Solution{
public:
  int longestPalindrome(string s) {
    int ans = 0;
    int size = s.length();
    unordered_map<char, int> m;
    for (int i = 0; i < size; i++) {
      m[s[i]]++;
    }
    unordered_map<char, int>::iterator it = m.begin();
    while (it != m.end()) {
      //cout << it->first << " " << it->second << endl;
      if (it->second % 2 == 0)
	ans += it->second;
      else
	ans += it->second - 1;
      ++it;
    }
    if (ans < size)
      ans++;
    return ans;
  }
};

int main()
{
  Solution s;
  string str = "ccc";
  cout << s.longestPalindrome(str);
  cout << endl;
  return 0;
}
