#include <iostream>
using namespace std;

class Solution{
public:
  string addBinary(string a, string b) {
    if (a.length() == 0)
      return b;
    if (b.length() == 0)
      return a;
    string ans;
    int carry = 0;
    int sum = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;
    while (i >= 0 && j >= 0) {
      sum = a[i] - '0' + b[j] - '0' + carry;
      i--;
      j--;
      carry = sum / 2;
      ans += sum % 2 + '0';
    }
    while (i >= 0) {
      sum = a[i] - '0' + carry;
      i--;
      carry = sum / 2;
      ans += sum % 2 + '0';
    }
    while (j >= 0) {
      sum = b[j] - '0' + carry;
      j--;
      carry = sum / 2;
      ans += sum % 2 + '0';
    }
    if (carry == 1)
      ans += '1';
    reverse(ans.begin(), ans.end());
    return ans;
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
