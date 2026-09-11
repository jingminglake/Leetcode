#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  vector<vector<string> > partition(string s) {
    vector<vector<string> > ans;
    vector<string> tempList;
    backtrack(s, 0, tempList, ans);
    return ans;
  }
  void backtrack(string& s, int start, vector<string>& tempList, vector<vector<string> >& ans) {
    if (s.length() == start) {
      ans.push_back(tempList);     
      return;
    }
    for (int i = start; i < s.length(); i++) {
      if (isPalindrome(s, start, i)) {
        tempList.push_back(s.substr(start, i-start+1));
	backtrack(s, i+1, tempList, ans);
	tempList.pop_back();
      }
    }
  }
  bool isPalindrome(string s, int i, int j) {
    while (i < j) {
      if (s[i++] != s[j--])
	return false;
    }
    return true;
  }
};

int main()
{
  Solution s;
  string ss = "aab";
  vector<vector<string> > res = s.partition(ss);
  vector<vector<string> >::iterator it = res.begin();
  while (it != res.end()) {
    for (string i : *it)
      cout << i << " ";
    cout << endl;
    ++it;
  }
  return 0;
}
