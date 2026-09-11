#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  bool hasAlternatingBits(int n) {
    bool res = true;
    bool last = (n & 1) ? true : false;
    while (n) {
      n >>= 1;
      bool cur = (n & 1) ? true : false;
      if (last == cur) {
	res = false;
        break;
      }
      last = cur;
      //cout << n << endl;
    }
    return res;
  }
};

int main()
{
  Solution s;
  cout << s.hasAlternatingBits(5) << endl;
  cout << s.hasAlternatingBits(7) << endl;
  cout << s.hasAlternatingBits(11) << endl;
  cout << s.hasAlternatingBits(10) << endl;
  cout << s.hasAlternatingBits(21) << endl;
  return 0;
}
