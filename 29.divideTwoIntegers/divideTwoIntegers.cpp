#include <iostream>
using namespace std;

class Solution{
public:
  int divide(int dividend, int divisor) {
    if (!divisor || (dividend == INT_MIN && divisor == -1))
      return INT_MAX;
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    long long dvd = labs(dividend);
    long long dvs = labs(divisor);
    int res = 0;
    while (dvd >= dvs) {
      long long temp = dvs, mutiple = 1;
      while (dvd >= (temp << 1)) {
	temp <<= 1;
	mutiple <<= 1;
      }
      dvd -= temp;
      res += mutiple;
    }
    return sign == 1 ? res : -res;
  }
};

int main()
{
  Solution s;
  cout << s.divide(35, 5) << endl;
  return 0;
}
