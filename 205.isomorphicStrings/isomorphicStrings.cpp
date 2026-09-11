#include <iostream>
#include <unordered_map>
using namespace std;

class Solution{
public:
  bool isIsomorphic(string s, string t) {
    int sSize = s.length();
    int tSize = t.length();
    if (sSize != tSize)
      return false;
    unordered_map<char, int> m1;
    unordered_map<char, int> m2;
    for (int i = 0; i < sSize; i++) {
      if (m1[s[i]] != m2[t[i]])
	return false;
      m1[s[i]] = i + 1; // defalut is 0,plus one to differ from defalut
      m2[t[i]] = i + 1;
    }
    return true;
  }
};

int main()
{
  Solution s;
  string str1 = "aba";
  string str2 = "baa";
  cout << s.isIsomorphic(str1, str2);
  cout << endl;
  return 0;
}
