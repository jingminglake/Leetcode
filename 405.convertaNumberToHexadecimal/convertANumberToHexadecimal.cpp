#include <iostream>
using namespace std;

class Solution{
public:
  string toHex(int num) {
    if (num == 0)
      return "0";
    string ans;
    char hex[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    while (num != 0) {
      ans = hex[num & 0x0000000f] + ans;
      num >>= 4;
      if (ans.length() == 8)
	break;
    }
    return ans;
  }
};

int main()
{
  Solution s;
  cout << s.toHex(-1);
  cout << endl;
  return 0;
}
