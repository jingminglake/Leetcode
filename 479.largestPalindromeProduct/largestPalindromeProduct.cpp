//clang++ largestPalindromeProduct.cpp -std=c++11

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
  int largestpalindrome(int n) {
    if (n == 1)
      return 9;
    long mod = pow(10, n);
    long high = (mod - 1) * (mod - 1);
    long left = high / mod;
    long right = high % mod;
    if (left == reverse(right))
      return high % 1337;
    long candiateNum;
    while (left > mod/10) {
      candiateNum = left * mod + reverse(left);
      for (long i = mod - 1; i * i > candiateNum; i--) {
	if (candiateNum % i == 0)
	  return candiateNum % 1337;
      }
      left--;
    }
    return -1;
  }
  long reverse(long num) {
    long reverseNum = 0;
    while (num) {
      reverseNum *= 10;
      reverseNum += num % 10;
      num /= 10;
    }
    return reverseNum;
  }
};
int main()
{
  Solution s;
  cout << s.largestpalindrome(5) << endl;
  return 0;
}
