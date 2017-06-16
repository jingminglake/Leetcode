#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int hammingWeight(uint32_t n) {
    int ans = 0;
    int i = 0;
    int size = CHAR_BIT * sizeof(n);
    while (i < size) {
      if ((n & 1) == 1)
	ans++;
      n >>= 1;
      i++;
    }
    return ans;
  }
};

int main()
{
  Solution s;
  cout << s.hammingWeight(11);
  cout << endl;
  return 0;
}
