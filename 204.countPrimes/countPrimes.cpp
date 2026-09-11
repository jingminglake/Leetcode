#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int countPrimes(int n) {
    int ans = 0;
    vector<bool> isPrime(n, true);
    for (int i = 2; i < n; i++) {
      if (isPrime[i]) {
	ans++;
	for (int j = 2; i*j < n; j++) {
	  isPrime[i*j] = false;
	}
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  cout << s.countPrimes(100);
  cout << endl;
  return 0;
}
