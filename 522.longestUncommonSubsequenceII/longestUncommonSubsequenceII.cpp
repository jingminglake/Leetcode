// clang++ longestUncommonSubsequenceII.cpp -std=c++11

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    class Compare {
    public:
        bool operator()(const string& s1, const string& s2) const {
            return s1.length() > s2.length() || (s1.length() == s2.length() && s1 < s2);
        }
    };
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), Compare());
        unordered_set<string> s;
        for (int i = 0; i < strs.size(); i++) {
            if (i + 1 < strs.size() && strs[i] == strs[i + 1]) {
                s.insert(strs[i]);
                continue;
            }
            if (s.count(strs[i]))
                continue;
            if (!isSubseqInSet(strs[i], s))
                return strs[i].size();
            s.insert(strs[i]);
        }
        return -1;
    }
    bool isSubseqInSet(string& str, unordered_set<string>& s) {
        for (string prev : s) {
            if (isSubseq(prev, str))
                return true;
        }
        return false;
    }
    bool isSubseq(string& str, string& pattern) {
        int p1 = 0, p2 = 0;
        while (p1 < str.length() && p2 < pattern.length()) {
            if (str[p1] == pattern[p2]) {
                p1++; p2++;
            } else {
                p1++;
            }
        }
        return p2 == pattern.length();
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
