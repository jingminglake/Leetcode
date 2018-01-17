#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length())
      return false;
    vector<int> hash1(26, 0);
    for (char c : s1)
      hash1[c - 'a']++;
    int left = 0, right = 0;
    vector<int> hash2(26, 0);
    while (right < s2.length()) {
      while (right - left < s1.length()) {
	hash2[s2[right++] - 'a']++;
      }
      if (hash1 == hash2)
	return true;
      hash2[s2[left++] - 'a']--;
    }
    return false;
  }
};

int main()
{
  Solution s;
  string s1 = "abc";
  string s2 = "acobabacsd";
  cout << s.checkInclusion(s1, s2);
  cout << endl;
  return 0;
}
