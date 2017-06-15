#include <iostream>
using namespace std;

bool isBadVersion(int num) {
  if (num >= 8)
    return true;
  else
    return false;
}

class Solution{
public:
  int firstBadVersion(int n) {
    int low = 1, high = n;
    while (low <= high) {
      int mid = low + (high-low)/2;
      if (isBadVersion(mid))
	high = mid - 1;
      else 
	low = mid + 1;
    }
    cout << low << " " << high << endl;
    return low;
  }
};

int main()
{
  Solution s;
  cout << s.firstBadVersion(10) << endl;
  return 0;
}
