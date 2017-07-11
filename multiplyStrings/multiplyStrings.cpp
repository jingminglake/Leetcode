#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution{
public:
  string multiply(string num1, string num2) {
    int size1 = num1.length(), size2 = num2.length();
    vector<int> pos(size1 + size2, 0);
    for (int i = size1 - 1; i >= 0; i--) {
      for (int j = size2 - 1; j >= 0; j--) {
	int mul = (num1[i] - '0') * (num2[j] - '0');
	int sum = pos[i + j + 1] + mul;
	pos[i + j] += sum / 10;
	pos[i + j + 1] = sum % 10;
      }
    }
    string ans = "";
    for (int i : pos) {
      if (!(ans == "" && i == 0))
	ans += to_string(i);
    }
    return ans == "" ? "0" : ans;
  }
};

int main()
{
  Solution s;
  string s1 = "123";
  string s2 = "456";
  cout << s.multiply(s1, s2);
  cout << endl;
  return 0;
}
