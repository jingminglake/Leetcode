// clang++ wordBreak.cpp -std=c++11

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    int len = s.length();
    vector<bool> dp(len + 1, false);
    dp[0] = true;
    unordered_set<string> set;
    for (string& word : wordDict)
      set.insert(word);
    for (int i = 1; i < len + 1; i++) {
      for (int j = i - 1; j >= 0; j--) {
	if (dp[j]) {
	  if (set.find(s.substr(j, i - j)) != set.end()) {
	    dp[i] = true;
	    break;
	  }
	}
      }//for
    }//for
    return dp[len];
  }
};

int main()
{
  Solution s;
  string ss = "leetcode";
  vector<string> dict = {"leet", "code"};
  cout << s.wordBreak(ss, dict) << endl;;
  return 0;
}
