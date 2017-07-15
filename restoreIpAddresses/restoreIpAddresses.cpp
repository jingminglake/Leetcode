#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    vector<string> tempList;
    backtrack(s, 0, tempList, ans);
    return ans;
  }
  void backtrack(string& s, int start, vector<string>& tempList, vector<string>& ans) {
    if (s.length() == start || tempList.size() > 4) {
      if (tempList.size() == 4) {
	string temp = tempList[0];
	for (int i = 1; i < 4; i++) {
	  temp += "." + tempList[i];
	}
	ans.push_back(temp);
      }
      return;
    }
    for (int i = start; i < s.length(); i++) {
      if (isValidIpSeg(s, start, i)) {
	tempList.push_back(s.substr(start, i-start+1));
	backtrack(s, i+1, tempList, ans);
	tempList.pop_back();
      }
    }
  }
  bool isValidIpSeg(string s, int start, int end) {
    if (end - start >= 3)
      return false;
    if (s[start] == '0' && start != end)
      return false;
    int seg = stol(s.substr(start, end-start+1));
    if (seg >= 0 && seg <= 255)
      return true;
    return false;
  }
};

int main()
{
  Solution s;
  string ss = "010010";
  vector<string> res = s.restoreIpAddresses(ss);
  vector<string>::iterator it = res.begin();
  while (it != res.end()) {
      cout << *it << " ";
    cout << endl;
    ++it;
  }
  return 0;
}
