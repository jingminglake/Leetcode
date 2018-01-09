#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int res = 0;
    if (s.length() == 0)
      return res;
    int left = 0, right = 0;
    unordered_map<char, int> hash;
    while (left < s.length() && right < s.length()) {
      unordered_map<char, int>::iterator it = hash.find(s[right]);
      if (it != hash.end()) {
	left = max(left, it->second + 1);
      }
      hash[s[right]] = right;
      res = max (res, right - left + 1);
      right++;
    }
    return res;
  }
};



int main()
{
  string s;
  cout << "please input a string:" << endl;
  cin >> s;
  Solution sl;
  cout << sl.lengthOfLongestSubstring(s) << endl;
}
