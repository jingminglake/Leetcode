#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int hammingWeight(uint32_t n) {
    int res = 0;
    while (n) {
      if ((n & 1) == 1)
	res++;
      n = n >> 1;
    }
    return res;
  }
};

int main()
{
  Solution s;
  cout << s.hammingWeight(11);
  cout << endl;
  return 0;
}
