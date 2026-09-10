#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> hm;
    int maxLength = 0;
    int n = s.length();
    int i = 0, j = 0;
    while (j < n) {
      unordered_map<char, int>::iterator it = hm.find(s[j]);
      if ( it != hm.end() ) { //find!
	if (i <= it->second) {
	  //cout << "-----1-1----" << endl;
	  i = it->second + 1;
	}
	  
	it->second = j;
      }else {
        //cout << s[j] << "---1---" << endl;
        hm.insert(make_pair<char, int>((char)s[j], (int)j));
      }
      //if (j - i + 1 > maxLength)
      //	maxLength = j - i + 1;
      maxLength = max(maxLength, j - i + 1);
      j++;
    }
    // cout <<  (int)hm.size() << "---"<< endl;
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
