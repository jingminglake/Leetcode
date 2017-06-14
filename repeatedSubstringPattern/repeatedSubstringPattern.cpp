#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  bool repeatedSubstringPattern(string s) {
    int size = s.length();
    if (size < 2)
      return false;
    for (int k = 2; k <= size; k++) {
      if (size % k != 0)
        continue;
      int len = size/k;
      string pattern = s.substr(0, len);
      bool flag = true;
      for (int i = 1; i < k; i++) {
	if (pattern != s.substr(len * i, len)) {
	  flag = false;
	  break;
	}
      }
      if (flag)
	return true;
    }
    return false;
  }
};

int main()
{
  Solution s;
  string str = "bab";
  cout << s.repeatedSubstringPattern(str) << endl;
  return 0;
}
