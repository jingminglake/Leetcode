#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int guess(int num) {
  if (num < 6)
    return 1;
  else if (num > 6)
    return -1;
  else
    return 0;
}

class Solution{
public:
  int guessNumber(int n) {
    int low = 1, high = n;
    while (low <= high) {
      int mid = low + (high-low)/2;
      if (guess(mid) == -1)
	high = mid - 1;
      else if (guess(mid) == 1)
	low = mid + 1;
      else 
	return mid;
    }
    return -1;
  }
};

int main()
{
  Solution s;
  cout << s.guessNumber(10) << endl;
  return 0;
}
