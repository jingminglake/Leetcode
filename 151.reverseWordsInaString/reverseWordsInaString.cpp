#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  void reverseWords(string& s) {
    reverse(s.begin(), s.end());
    int realLength = 0;
    int size = s.length();
    int i = 0;
    while (i < size) {
      if (s[i] != ' ') {
	if (realLength != 0)
	  s[realLength++] = ' ';
	int start = i;
	while (i < size && s[i] != ' ')
	  s[realLength++] = s[i++];
	reverse(s.begin() + realLength - (i - start), s.begin() + realLength);
      } else {
	i++;
      }
    }
    s.erase(s.begin() + realLength, s.end());   
  }
};

int main()
{
  Solution s;
  string ss = "the   sky  is ";
  s.reverseWords(ss);
  cout << ss;
  cout << endl;
  return 0;
}
