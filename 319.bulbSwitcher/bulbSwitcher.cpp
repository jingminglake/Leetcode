#include <iostream>
#include <cmath>
using namespace std;

class Solution{
public:
  int bulbSwitch(int n) {
    return sqrt(n);
  }
};

int main()
{
  Solution s;
  cout << s.bulbSwitch(37) << endl;
  return 0;
}
