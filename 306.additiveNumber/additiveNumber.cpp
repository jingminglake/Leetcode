#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  bool isAdditiveNumber(string num) {
    if (num.length() < 3)
      return false;
    for (int i = 1; i <= num.length() / 2; i++) {
      if (num[0] == '0' && i > 1) 
	return false;
      string first = num.substr(0, i);
      for (int j = 1; num.length() - i - j >= max (i, j); j++) {
	if (num[i] == '0' && j > 1)
	  break;
	string second = num.substr(i, j);
	if (isValidAdditive(first, second, i + j, num))
	  return true;
      }
    }
    return false;
  }
  bool isValidAdditive(string first, string second, int start, string num) {
    if (start == num.length())
      return true;
    string third = to_string(stoll(first) + stoll(second));
    if (num.substr(start, third.length()) == third)
      return isValidAdditive(second, third, start + third.length(), num);
    else
      return false;
  }
};

int main()
{
  Solution s;
  string num = "112358";
  string num2 = "123";
  string num3 = "111";
  cout << s.isAdditiveNumber(num) << endl;
  cout << s.isAdditiveNumber(num2) << endl;
  cout << s.isAdditiveNumber(num3) << endl;
  return 0;
}
