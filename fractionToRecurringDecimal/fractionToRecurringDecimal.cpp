// clang++ fractionToRecurringDecimal.cpp -std=c++11

#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution{
public:
  string fractionToDecimal(int numerator, int denominator) {
    string ans;
    if (denominator == 0)
      return ans;
    if (numerator == 0)
      return "0";
    ans += ((numerator > 0) ^ (denominator > 0)) ? "-" : "";
    long num = labs(numerator);
    long den = labs(denominator);
    ans += to_string(num/den);//integer part
    num %= den;
    if (num == 0)
      return ans;
    // fractional part
    ans += '.';
    unordered_map<long, int> m;
    m[num] = ans.length();
    unordered_map<long, int>::iterator it;
    while (num != 0) {
      num *= 10;
      ans += to_string(num/den);
      num %= den;
      it = m.find(num);
      if (it != m.end()) {
	ans.insert(it->second, "(");
	ans += ")";
	break;
      } else {
	m[num] = ans.length();
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  cout << s.fractionToDecimal(-1, -2147483648);
  cout << endl;
  return 0;
}
