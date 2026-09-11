#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Solution{
public:
  int countNumbersWithUniqueDigits(int n) {
    int ans = 10;
    if (n == 0)
      return 1;
    int uniqueDigitsNumInAFixedLen = 9;
    int availableDigitsNum = 9;
    while (n-- > 1 && availableDigitsNum > 0) {
      uniqueDigitsNumInAFixedLen = uniqueDigitsNumInAFixedLen * availableDigitsNum;
      ans += uniqueDigitsNumInAFixedLen;
      availableDigitsNum--;
    }
    return ans;
  }
};

int main()
{
  Solution s;
  cout << s.countNumbersWithUniqueDigits(3);
  cout << endl;
  return 0;
}
