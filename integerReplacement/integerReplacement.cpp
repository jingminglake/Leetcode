#include <iostream>
#include <cmath>
#include <unordered_map>
#include <ctime>
#include <cstdlib>
using namespace std;

class Solution{
public:
  int integerReplacement(int n) {
    if (n == INT_MAX)
      return 32;
    if (n <= 3)
      return n-1;
    int ans = 0;
    if (n % 2 == 0)
      return 1 + integerReplacement(n / 2);
    else if ((n + 1) % 4 == 0)
      return 2 + integerReplacement((n+1) / 2);
    else
      return 2 + integerReplacement((n-1) / 2);
  }
};

int main()
{
  Solution s;
  cout << s.integerReplacement(8) << endl;
  return 0;
}
