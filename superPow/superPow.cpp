#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution{
public:
  int superPow(int a, vector<int>& b) {
    if (b.empty())
      return 1;
    int last_digit = b.back();
    b.pop_back();
    return powmod(superPow(a, b), 10) * powmod(a, last_digit) % 1337;
  }
  int powmod(int a, int k) {
    int res = 1;
    a %= 1337;
    for (int i = 0; i < k; i++) {
      res = (res * a) % 1337;
    }
    return res;
  }
};

int main()
{
  Solution s;
  int a[2] = {1,0};
  vector<int> vec(a, a+2);
  cout << s.superPow(2, vec);
  cout << endl;
  return 0;
}
