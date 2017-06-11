#include <iostream>
using namespace std;

class Solution{
public:
  int mySqrt(int x) {
    if (x == 0)
      return 0;
    long long left = 1, right = x;
    while (left <= right) {
       long long mid = left + (right-left)/2;
      if (mid * mid > x)
	right = mid - 1;
      else if (mid * mid < x)
	left = mid + 1;
      else
	return mid;
    }
    return left - 1;
  }
};

int main()
{
  Solution s;
  cout << s.mySqrt(35) << endl;
  return 0;
}
