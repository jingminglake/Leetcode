// clang++ waterAndJugProblem.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
  bool canMeasureWater(int x, int y, int z) {
    return z == 0 || (x + y >= z && z % gcd(x, y) == 0);
  }
  int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
  }
};

int main()
{
  Solution s;
  cout << s.canMeasureWater(3, 5, 4) << endl;
  cout << s.canMeasureWater(2, 6, 5) << endl;
  return 0;
}
