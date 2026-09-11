#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int integerBreak(int n) {
    if (n == 2)
      return 1;
    if (n == 3)
      return 2;
    if (n == 4)
      return 4;
    int product = 1;
    while (n > 4) {
      product *= 3;
      n -= 3;
    }
    product *= n;
    return product;
  }
};

int main()
{
  Solution s;
  cout << s.integerBreak(10);
  cout << endl;
  return 0;
}
