#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int lengthOfLastWord(string s) {
    int ans = 0;
    int i = s.length() - 1;
    while (s[i] == ' ')
      i--;
    for (i; i >= 0; i--) {
      if (isalpha(s[i]))
	ans++;
      else
	break;
    }
    return ans;
  }
};

int main()
{
  Solution s;
  string str = "hello world";
  cout << s.lengthOfLastWord(str) << endl;
  return 0;
}
