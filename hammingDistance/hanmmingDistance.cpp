#include <iostream>
using namespace std;

class Solution{
public:
  int hammingDistance(int x, int y) {
    uint32_t ans = 0;
    int n = x^y;
    for (int i = 0; i < 32; i++) {
      if ((n&1) == 1)
	ans++;
      n >>= 1;
    }
    return ans;
  }
};

int main()
{
  Solution s;
  cout << s.hammingDistance(1, 4);
  cout << endl;
  return 0;
}
