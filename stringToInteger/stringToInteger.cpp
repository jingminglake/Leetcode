#include <iostream>
using namespace std;

class Solution{
public:
  int myAtoi(string str) {
    long long ans = 0;
    int i = 0;
    int sign = 1;
    while(str[i] == ' ')
      i++;
    if(str[i] == '+' || str[i] == '-') {
      if(str[i] == '-')
	sign = -1;
      i++;
    }
    while(isDigit(str[i])) {
      ans *= 10;
      ans += (int) (str[i] - '0');
      i++;
      if (ans * sign > INT_MAX)
	return INT_MAX;
      else if(ans * sign < INT_MIN)
	return INT_MIN; 
    }
    return ans * sign;  
  }
  bool isDigit(char& c) {
    if(c < '0' || c > '9')
      return false;
    else
      return true;
  }
};

int main()
{
  Solution s;
  string ss = "-1123111111111111111";
  //int a = atoi(ss.c_str());
  
  cout << s.myAtoi(ss) << endl;
  return 0;
}
