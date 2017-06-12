#include <iostream>
#include <cmath>
using namespace std;

class Solution{
public:
  int arrangeCoins(int n) {
    /*int left = 0, right = n;
    while (left <= right) {
      long long mid = left + (right - left)/2;
      if(mid*(mid+1)*0.5 > n)
	right = mid - 1;
      else if(mid*(mid+1)*0.5 < n)
	left = mid + 1;
      else
	return mid;
    }
    return right;*/
    //return int((-1 + sqrt(1 + 8 * (long)n))/2);
    return int(sqrt(0.25 + 2*(long)n) - 0.5);
  }
};

int main()
{
  Solution s;
  cout << s.arrangeCoins(17)<< endl;
  return 0;
}
