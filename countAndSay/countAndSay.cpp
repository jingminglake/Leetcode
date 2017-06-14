#include <iostream>
using namespace std;

class Solution{
public:
  string countAndSay(int n) {
    string ans;
    if (n < 0)
      return ans;
    ans = "1";
    while (--n) {
      int size = ans.size();
      char c = ans[0];
      int i = 1;
      int count = 1;
      string temp = "";
      while (i < size) {
	if (ans[i] == c) {
	  count++;
	  i++;
	} else {
	  temp += to_string(count) + c;
	  c = ans[i];
	  count = 1;
	  i++;
	}
      }
      temp += to_string(count) + c;
      ans = temp;
    }
    return ans;
  }
};

int main()
{
  Solution s;
  cout << s.countAndSay(5) << endl;
  return 0;
}
