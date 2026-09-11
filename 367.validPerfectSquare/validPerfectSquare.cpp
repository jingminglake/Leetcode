#include <iostream>
using namespace std;

class Solution{
public:
  bool isPerfectSquare(int num) {
    int left = 1, right = num;
    while (left <= right) {
      long long mid = left + (right - left)/2;
      if (mid * mid > num)
	right = mid - 1;
      else if (mid * mid < num)
	left = mid + 1;
      else
	return true;
    }
    return false;
  }
};

int main()
{
  Solution s;
  cout << s.isPerfectSquare(14)<< endl;
  return 0;
}
