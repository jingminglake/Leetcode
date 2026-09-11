#include <iostream>
using namespace std;

class Solution{
public:
  bool checkPerfectNumber(int num) {
    int ans = 0;
    if (num == 1)
      return false;
    for(int i = 2; i*i <= num; i++) {
      if (num % i == 0)
	ans += i + num / i;
    }
    ans++; // consider the divisor 1
    return ans == num;
  }
};

int main()
{
  Solution s;
  cout << s.checkPerfectNumber(28) << endl;
  return 0;
}
