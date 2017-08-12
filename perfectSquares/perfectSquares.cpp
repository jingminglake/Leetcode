#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int numSquares(int n) {
    vector<int> m(n+1, INT_MAX);
    m[0] = 0;
    for (int i = 1; i <= n; i++) {
      int minM = INT_MAX;
      for (int j = 1; i - j*j >=0; j++) {
	minM = min(minM, m[i - j*j] + 1);
      }
      m[i] = minM;
    }
    return m[n];
  }
};

int main()
{
  Solution s; 
  cout << s.numSquares(12) << endl;
  return 0;
}
