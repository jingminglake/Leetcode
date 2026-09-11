#include <iostream>
#include <unordered_map>
using namespace std;

class Solution{
public:
  int addDigits(int num) {
    /* int ans = 0;
    if (num < 10)
      return num;
    while (num > 0) {
      ans += num % 10;
      num = num / 10;
    }
    return addDigits(ans);*/
    return 1 + (num - 1) % 9;
  }
};

int main()
{
  Solution s;
  cout << s.addDigits(38) << endl;
  return 0;
}
