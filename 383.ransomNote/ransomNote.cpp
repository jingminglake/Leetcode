#include <iostream>
#include <unordered_map>
using namespace std;

class Solution{
public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> m;
    for(int i = 0; i < magazine.size(); i++) {
      m[magazine[i]]++;
    }
    for(int i = 0; i < ransomNote.size(); i++) {
      if (--m[ransomNote[i]] < 0)
	return false;
    }
    return true;
  }
};

int main()
{
  Solution s;
  string str1 = "aa";
  string str2 = "ab";
  cout << s.canConstruct(str1, str2) << endl;
  return 0;
}
