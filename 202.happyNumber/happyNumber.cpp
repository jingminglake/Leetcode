#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
public:
  bool isHappy(int n) {
    unordered_set<int> set;
    int squareSum = 0;
    int oldN = 0;
    while (set.find(n) == set.end()) {
      squareSum = 0;
      oldN = n;
      while (n > 0) {
	squareSum += (n%10) * (n%10);
	n /= 10;
      }
      if (squareSum == 1) {
	return true;
      }
      else {
	set.insert(oldN);
	n = squareSum;
      }
    }
    return false;
  }
};

int main()
{
  Solution s;
  cout << s.isHappy(19);
  cout << endl;
  return 0;
}
