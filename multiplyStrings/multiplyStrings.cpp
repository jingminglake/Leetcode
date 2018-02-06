#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  string multiply(string num1, string num2) {
    string res;
    vector<int> vec(num1.size() + num2.size(), 0);
    for (int i = num1.size() - 1; i >= 0; i--) {
      for (int j = num2.size() - 1; j >= 0; j--) {
	int p1 = i + j, p2 = i + j + 1;
	int multiRes = (num1[i] - '0') * (num2[j] - '0') + vec[p2];
	vec[p1] += multiRes / 10;
	vec[p2] = multiRes % 10;
      }
    }
    for (int digit : vec)
      res += to_string(digit);
    size_t index = res.find_first_not_of('0');
    if (index == string::npos)
      return "0";
    else
      return res.substr(index);
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
