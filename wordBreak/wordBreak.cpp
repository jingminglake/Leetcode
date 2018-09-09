// clang++ wordBreak.cpp -std=c++11

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len_s = s.length();
        vector<int> dp(len_s + 1, false);
        dp[0] = true;
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        for (int i = 1; i <= len_s; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len_s];
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
