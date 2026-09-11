#include <iostream>
using namespace std;

class Solution{
public:
  double myPow(double x, int n) {
    long long N = n;
    if (N == 0)
      return 1;
    if (N < 0) {
      N = -N;
      x = 1/x;
    }
    return (N % 2 == 0) ? myPow(x * x, N / 2) : x * myPow (x * x, N / 2); 
  }
};

int main()
{
  Solution s;
  cout << s.myPow(2, 5) << endl;
  return 0;
}
