#include <iostream>
using namespace std;

class Solution{
public:
  int countSegments(string s) {
    int ans = 0;
    int i = 0;
    int size = s.length();
    if (size < 1)
      return 0;
    while (i < size && s[i] == ' ')
      i++;
    if (i < size && s[i] != ' ')
      ans += 1;
    for(i; i < s.length(); i++) {
      if (s[i] == ' ') {
	while (i < size && s[i] == ' ')
	  i++;
	if (i < size && s[i] != ' ')
	  ans += 1;
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  string str = "       ";
  cout << s.countSegments(str) << endl;
  return 0;
}
