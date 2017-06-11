#include <iostream>
using namespace std;

class Solution{
public:
  bool isPowerOfTwo(int n) {
    if (n == 1)
      return true;
    if (n%2 != 0 || n == 0) 
      return false;
    else
      return isPowerOfTwo(n/2);
  }
};

int main()
{
  Solution s;
  cout << s.isPowerOfTwo(8)<< endl;
  return 0;
}
