#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int> res;
    int i = left;
    while (i <= right) {
      int n = i;
      bool isSelfDividing = true;
      while (n) {
	int r = n % 10;
	n /= 10;
	if ( r == 0 || (i % r != 0) ) {
	  isSelfDividing = false;
	  break;
	}
      }
      if (isSelfDividing)
	res.push_back(i);
      i++;
    }//while
    return res;
  }
};

int main()
{
  Solution s;
  vector<int> res = s.selfDividingNumbers(1, 22);
  for (int i : res)
    cout << i << " ";
  cout << endl;
  return 0;
}
