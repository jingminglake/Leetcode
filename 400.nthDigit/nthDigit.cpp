#include <iostream>
using namespace std;

class Solution{
public:
  int findNthDigit(int n) {
    long long base = 9, bits = 1, start = 1;
    while (n > base * bits) {
      n -= base * bits;
      bits++;
      base *= 10;
      start *= 10;
    }
    string s = to_string(start + (n-1)/bits);
    return s[(n-1)%bits] - '0';
  }
};

int main()
{
  Solution s;
  cout << s.findNthDigit(150)<< endl;
  return 0;
}
