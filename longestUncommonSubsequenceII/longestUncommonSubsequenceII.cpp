// clang++ splitArrayIntoConsecutiveSubsequences2.cpp -std=c++11

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Comp {
public:
    bool operator()(const string& s1, const string& s2) const {
        if (s1.length() == s2.length())
            return s1 > s2;
        return s1.length() > s2.length();
    }
};
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), Comp());
        unordered_set<string> s;
        for (int i = 0; i < strs.size(); i++) {
            if (s.count(strs[i]))
                continue;
            bool isSub = false;
            if (i == strs.size() - 1 || strs[i] != strs[i + 1]) {
                for (string str : s) {
                    int j = 0;
                    for (char c : str) {
                        if (c == strs[i][j])
                            j++;
                        if (j == strs[i].size())
                            break;
                    }
                    if (j == strs[i].size()) {
                        isSub = true;
                        break;
                    }
                }
                if (!isSub)
                    return strs[i].size();
            }
            s.insert(strs[i]);
        } // for
        return -1;
    }
};
int main()
{
  Solution s;
  vector<string> strs = {"aba", "cdc", "eae"};
  cout << s.findLUSlength(strs);
  cout << endl;
  return 0;
}
