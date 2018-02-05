#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  string longestCommonPrefix(vector<string>& strs) {
    string res; 
    if (strs.size() == 0)
      return res;
    for (int j = 0; j < strs[0].size(); j++) {
      for (int i = 1; i < strs.size(); i++) {
	if (j >= strs[i].size() || strs[i][j] != strs[0][j]) {
	  return res;
	}
      }
      res += strs[0][j];
    }
    return res;
  }
};

int main()
{
  Solution s;
  vector<string> vec = {"abc", "ab", "abcd"};
  cout << s.longestCommonPrefix(vec);
  cout << endl;
  return 0;
}
