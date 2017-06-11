#include <iostream>
using namespace std;

class Solution{
public:
  string addStrings(string num1, string num2) {
    int carry = 0;
    string ans = "";
    int sum = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    while (i >= 0 && j >= 0) {
      sum = num1[i] - '0' + num2[j] - '0' + carry;
      i--;
      j--;
      carry = sum / 10;
      ans = ans + to_string(sum%10);
    }
    while (i >= 0) {
      sum = num1[i] - '0' + carry;
      i--;
      carry = sum / 10;
      ans += to_string(sum%10);
    }
    while (j >= 0) {
      sum = num2[j] - '0' + carry;
      j--;
      carry = sum / 10;
      ans += to_string(sum%10);
    }
    if (carry == 1)
      ans += "1";
    // cout << i << " " << j << endl;
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main()
{
  Solution s;
  string str1 = "999";
  string str2 = "1";
  cout << s.addStrings(str1, str2)<< endl;
  return 0;
}
