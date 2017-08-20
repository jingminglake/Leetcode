#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  bool checkInclusion(string s1, string s2) {
    int hash[26] = {0};
    int size1 = s1.length();
    int size2 = s2.length();
    for (int i = 0; i < size1; i++) {
      hash[s1[i] - 'a']++;
    }
    for (int i = 0; i < size2; i++) {
      hash[s2[i] - 'a']--;
      if (i >= size1)
	hash[s2[i - size1] - 'a']++;
      if (checkAllZero(hash))
	return true;
    }
    return false;
  }
  bool checkAllZero(int hash[]) {
    for (int i = 0; i < 26; i++) {
      if (hash[i] != 0)
	return false;
    }
    return true;
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
