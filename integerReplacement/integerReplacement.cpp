#include <iostream>
using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1)
            return 0;
        long m = n;
        if (m % 2 == 0)
            return integerReplacement(m / 2) + 1;
        else
            return min (integerReplacement((m + 1) / 2), integerReplacement((m - 1) / 2) ) + 2;
    }
};

int main()
{
  Solution s;
  cout << s.integerReplacement(8) << endl;
  return 0;
}
