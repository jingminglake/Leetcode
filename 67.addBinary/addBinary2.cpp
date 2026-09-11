#include <iostream>
using namespace std;

class Solution{
public:
  string addBinary(string a, string b) {
    string res;
    int carry = 0;
    int i = a.length() - 1, j = b.length() - 1;
    while (i >= 0 || j >= 0 || carry != 0) {
      int sum = 0;
      if (i >= 0)
	sum += a[i] - '0';
      if (j >= 0)
	sum += b[j] - '0';
      sum += carry;
      res = to_string(sum % 2) + res;
      carry = sum / 2;
      i--;
      j--;
    }
    return res;
  }
};

int main()
{
  Solution s;
  string str1 = "11";
  string str2 = "1";
  cout << s.addBinary(str1, str2)<< endl;
  return 0;
}
