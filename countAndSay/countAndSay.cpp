#include <iostream>
using namespace std;

class Solution {
public:
  string countAndSay(int n) {
    string res = "";
    if (n <= 0)
      return res;
    res = "1";
    if (n == 1)
      return res;
    while (n > 1) {
      string temp;
      char c = res[0];
      int count = 1;
      for (int i = 1; i < res.length(); i++) {
	if (res[i] == res[i - 1]) {
	  count++;
	} else {
	  temp += to_string(count) + c;
	  c = res[i];
	  count = 1;
	}
      }
      temp += to_string(count) + c;
      res = temp;
      n--;
    }
    return res;
  }
};

int main()
{
  Solution s;
  cout << s.countAndSay(5) << endl;
  return 0;
}
