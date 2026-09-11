#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int firstUniqChar(string s) {
    int hash[26] = {0};
    int size = s.length();
    for (int i = 0; i < size; i++) {
      hash[s[i] - 'a']++;
    }
    for (int i = 0; i < size; i++) {
      if (hash[s[i] - 'a'] == 1)
	return i;
    }
    return -1;
  }
};

int main()
{
  Solution s;
  string str = "loveleetcode";
  cout << s.firstUniqChar(str);
  cout << endl;
  return 0;
}
