#include <iostream>
#include <cmath>
using namespace std;

class Solution{
public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    int pigs = 0;
    while (pow(minutesToTest/minutesToDie + 1, pigs) < buckets)
      pigs++;
    return pigs;
  }
};

int main()
{
  Solution s;
  cout << s.poorPigs(1000, 15, 60);
  cout << endl;
  return 0;
}
