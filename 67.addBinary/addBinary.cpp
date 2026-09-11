#include <iostream>
using namespace std;

class Solution{
public:
  string addBinary(string a, string b) {
    string res;
    int carry = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int i = 0, j = 0;
    while (i < a.length() || j < b.length() || carry != 0) {
      int sum = 0;
      if (i < a.length())
	sum += a[i] - '0';
      if (j < b.length())
	sum += b[j] - '0';
      sum += carry;
      res += sum % 2 + '0';
      carry = sum / 2;
      i++;
      j++;
    }
    reverse(res.begin(), res.end());
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
