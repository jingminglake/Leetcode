// clang++ wordBreakII.cpp -std=c++11

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string> > m;
        return helper(s, wordDict, m);
    }
    vector<string> helper(string s, vector<string>& wordDict, unordered_map<string, vector<string> >& m) {
        if (m.count(s))
            return m[s];
        if (s.empty())
            return {""};
        vector<string> res;
        for (string word : wordDict) {
            if (s.substr(0, word.size()) != word)
                continue;
            vector<string> tempR = helper(s.substr(word.size()), wordDict, m);
            for (string str : tempR) {
                res.push_back(word + (str.empty() ? "" : " ") + str);
            }
        }
        return m[s] = res;
    }
};

int main()
{
  Solution s;
  string ss = "pineapplepenapple";
  vector<string> dict = {"apple", "pen", "applepen", "pine", "pineapple"};
  for (string& str : s.wordBreak(ss, dict)) {
      cout << str << endl;
  }
  return 0;
}
