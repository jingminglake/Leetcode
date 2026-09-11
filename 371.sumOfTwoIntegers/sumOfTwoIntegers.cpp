#include <iostream>
using namespace std;

class Solution{
public:
  int getSum(int a, int b) {
    if (a == 0)
      return b;
    if (b == 0)
      return a;
    int carry = a & b;
    int ans = a ^ b;
    while (carry != 0) {
      b = carry << 1;
      carry = ans & b;
      ans = ans ^ b;
    }   
    return ans;
  }
};

int main()
{
  Solution s;
  cout << s.getSum(5,3);
  cout << endl;
  return 0;
}
