// clang++ uniqueSubstringInWraparoundString.cpp -std=c++11

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution{
public:
  int findSubstringInWraproundString(string p) {
    vector<int> m(26, 0);
    int size = p.length();
    int len = 0;
    for (int i = 0; i < size; i++) {
      if (i > 0 && (p[i] == p[i - 1] + 1 || p[i - 1] - p[i] == 25)) {
	len++;
      } else {
	len = 1;
      }
      m[p[i] - 'a'] = max(m[p[i] - 'a'], len);
    }
    return accumulate(m.begin(), m.end(), 0);
  }
};

int main()
{
  Solution s;
  string ss1 = "cac";
  string ss2 = "zab";
  cout << s.findSubstringInWraproundString(ss1) << endl;
  cout << s.findSubstringInWraproundString(ss2) << endl;
  return 0;
}
