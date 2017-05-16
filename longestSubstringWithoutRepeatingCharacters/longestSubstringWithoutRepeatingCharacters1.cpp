#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> hs;
    int maxLength = 0;
    int n = s.length();
    int i = 0, j = 0;
    while (i < n && j < n) {
      unordered_set<char>::const_iterator it = hs.find(s[j]);
      if ( it != hs.end() ) { //find!
	hs.erase(s[i++]);
      }else {
	cout << s[j] << "---1---" << endl;
	hs.insert(s[j++]);
	if (hs.size() > maxLength)
	  maxLength = hs.size();
      }
    }
    return maxLength;
  }
};



int main()
{
  string s;
  cin >> s;
  Solution sl;
  cout << sl.lengthOfLongestSubstring(s) << endl;
}
