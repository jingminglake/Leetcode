// clang++ isSubsequence.cpp -std=c++11

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  bool isSubsequence(string s, string t) {
    int p1 = 0, p2 = 0;
    int size1 = s.length();
    int size2 = t.length();
    if (size1 == 0)
      return true;
    while (p2 < size2) {
      if (s[p1] == t[p2])
	p1++;
      if (p1 == size1)
	return true;
      p2++;
    }
    return false;
  }
};

int main()
{
  Solution s;
  string s1 = "abc";
  string s2 = "ahbgdc";
  cout << s.isSubsequence(s1, s2) << endl;
  return 0;
}
