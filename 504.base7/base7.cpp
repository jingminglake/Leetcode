#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  string convertToBase7(int num) {
    string ans;
    int sign = 1;
    if (num < 0) {
      sign = -1;
      num = -num;
    }
    if (num == 0)
      return "0";
    while (num != 0) {
      ans += to_string(num % 7);
      num /= 7;
    }
    if (sign == -1)
      ans += "-";
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main()
{
  Solution s;
  cout << s.convertToBase7(0);
  cout << endl;
  return 0;
}
