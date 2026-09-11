// clang++ superUglyNumber.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;


class Solution{
public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<long> uglys(n);
    int pSize = primes.size();
    vector<long> p(pSize, 0);
    uglys[0] = 1;
    for (int i = 1; i < n; i++) {
      int minUgly = INT_MAX;
      for (int j = 0; j < pSize; j++) {
	minUgly = min<long>(minUgly, primes[j] * uglys[p[j]]);
      }
      uglys[i] = minUgly;
      for (int j = 0; j < pSize; j++) {
	if (uglys[p[j]] * primes[j] == minUgly) {
	  p[j]++;
	}
      }
    }
    return uglys[n-1];
  }
};

int main()
{
  Solution s;
  vector<int> primes = {2,7,13,19};
  cout << s.nthSuperUglyNumber(12, primes);
  cout << endl;
  return 0;
}
