#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int findLUSlength(string a, string b) {
    return (a == b) ? -1 : max(a.length(), b.length());
  }
};

int main()
{
  Solution s;
  string str1 = "aba";
  string str2 = "cdc";
  cout << s.findLUSlength(str1, str2) << endl;
  return 0;
}
