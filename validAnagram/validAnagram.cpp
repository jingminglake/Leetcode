#include <iostream>
#include <unordered_map>
using namespace std;

class Solution{
public:
  bool isAnagram(string s, string t) {
    int sSize = s.size();
    int tSize = t.size();
    if (sSize != tSize)
      return false;
    unordered_map<char, int> m;
    for (int i = 0; i < sSize; i++) {
      m[s[i]]++;
      m[t[i]]--;
    }
    unordered_map<char, int>::iterator it = m.begin();
    while (it != m.end()) {
      if (it->second != 0)
	return false;
      ++it;
    }
    return true;
  }
};

int main()
{
  Solution s;
  string str1 = "anagram";
  string str2 = "nagaram";
  cout << s.isAnagram(str1, str2);
  cout << endl;
  return 0;
}
