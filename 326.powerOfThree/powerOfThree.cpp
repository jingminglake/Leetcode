#include <iostream>
using namespace std;

class Solution{
public:
  bool isPowerOfThree(int n) {
    /* if (n == 1)
      return true;
    if (n == 0 || n%3 != 0)
      return false;
    else
    return isPowerOfThree(n/3);*/
    
    // 1162261467 is 3^19,  3^20 is bigger than int  
    return ( n>0 && 1162261467%n == 0);
  }
};

int main()
{
  Solution s;
  cout << s.isPowerOfThree(3)<< endl;
  return 0;
}
