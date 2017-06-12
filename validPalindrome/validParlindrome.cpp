#include <iostream>
using namespace std;

class Solution{
public:
  bool isPalindrome(string s) {
    int i = 0, j = s.length() - 1; 
    while (i < j) {
      if (!isalnum(s[i])) {
	i++;
	continue;
      }
      if (!isalnum(s[j])) {
	j--;
	continue;
      }
      if (tolower(s[i]) == tolower(s[j])) {
	i++;
	j--;
      } else {
	return false;
      }  
    }
    return true;
  }
};

int main()
{
  Solution s;
  //string str = "A man, a plan, a canal: Panama";
  string str = "0P";
  cout << s.isPalindrome(str) << endl;
  return 0;
}
