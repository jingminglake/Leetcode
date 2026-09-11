#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  char findTheDifference(string s, string t) {
    char ans;
    if (s.empty())
      return t[0];
    int hash[26] = {0};
    int size = s.length();
    for (int i = 0; i < size; i++) {
      hash[s[i] - 'a']++;
    }
    for (int j = 0; j < size + 1; j++) {
      --hash[t[j] - 'a'];
    }
    for (int k = 0; k < 26; k++) {
      if (hash[k] != 0)
	ans = char('a' + k);
    }
    return ans;
  }
};

int main()
{
  Solution s;
  string ss = "abcd";
  string p = "abcde";
  cout << s.findTheDifference(ss, p);
  cout << endl;
  return 0;
}
