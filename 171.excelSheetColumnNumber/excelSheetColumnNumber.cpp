#include <iostream>
#include <cmath>
using namespace std;

class Solution{
public:
  int titleToNumber(string s) {
    int ans = 0;
    int i = s.length() - 1;
    int base = 1; 
    while (i >= 0) {
      ans += (s[i] - 'A' + 1) * base;
      base *= 26;
      i--;
    }
    return ans;
  }
};

int main()
{
  Solution s;
  string str = "A";
  cout << s.titleToNumber(str)<< endl;
  return 0;
}
