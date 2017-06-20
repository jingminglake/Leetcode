#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  bool canWinNim(int n) {
    /* vector<bool> m(n+1, false);
    m[1] = true;
    m[2] = true;
    m[3] = true;
    for (int i = 3; i <= n; i++)
      m[i] = !m[i-1] || !m[i-2] || !m[i-3];
      return m[n];*/
    return n % 4 != 0;
  }
};

int main()
{
  Solution s;
  cout << s.canWinNim(100);
  cout << endl;
  return 0;
}
