// clang++ uglyNumberII.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;


class Solution{
public:
  int nthUglyNumber(int n) {
    vector<long> uglys(n);
    uglys[0] = 1;
    int p2 = 0, p3 = 0, p5 = 0;
    for (int i = 1; i < n; i++) {
      int m2 = uglys[p2] * 2;
      int m3 = uglys[p3] * 3;
      int m5 = uglys[p5] * 5;
      int minUgly = min<long>(m2, min<long>(m3, m5));
      uglys[i] = minUgly;
      if (minUgly == m2)
	p2++;
      if (minUgly == m3)
	p3++;
      if (minUgly == m5)
	p5++;
    }
    return uglys[n-1];
  }
};

int main()
{
  Solution s;
  cout << s.nthUglyNumber(10);
  cout << endl;
  return 0;
}
