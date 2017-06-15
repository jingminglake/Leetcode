#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int climbStairs(int n) {
    if (n <= 0)
      return 0;
    vector<int> m(n+1, 0);
    m[1] = 1;
    m[2] = 2;
    for (int i = 3; i <= n; i++) {
      m[i] = m[i-1] + m[i-2];
    }
    return m[n];
  } 
};

int main()
{
  Solution s;
  cout << s.climbStairs(10) << endl;
  return 0;
}
