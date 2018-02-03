#include <iostream>
using namespace std;

class Solution{
public:
  string countAndSay(int n) {
    string res;
    if (n == 1) {
      res = "1";
      return res;
    }
    string tempRes = countAndSay(n - 1);
    char curBit = tempRes[0];
    int count = 1;
    for (int i = 1; i < tempRes.size(); i++) {
      if (tempRes[i] == curBit) {
	count++;
      } else {
	res += to_string(count) + curBit;
	curBit = tempRes[i];
	count = 1;
      }
    }
    res += to_string(count) + curBit;
    return res;
  }
};

int main()
{
  Solution s;
  cout << s.countAndSay(5) << endl;
  return 0;
}
