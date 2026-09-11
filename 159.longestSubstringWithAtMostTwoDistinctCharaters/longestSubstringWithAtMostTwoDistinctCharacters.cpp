#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0;
        if (s.length() < 1)
            return res;
        unordered_map<char, int> m;
        int left = 0, right = 0;
        while (right < s.length()) {
            if (m.size() <= 2) {
                m[s[right]] = right; // may increase m.size()
                right++;
            }
            if (m.size() > 2) {
                int leftMost = s.length();
                for (auto& p : m) {
                    leftMost = min (leftMost, p.second);
                }
                m.erase(s[leftMost]);
                left = leftMost + 1;
            }
            res = max (res, right - left);
        }
        return res;
    }
};

int main() {
    Solution s;
    string str1 = "eceba";
    string str2 = "ccaabbb";
    cout << s.lengthOfLongestSubstringTwoDistinct(str1) << endl;
    cout << s.lengthOfLongestSubstringTwoDistinct(str2) << endl;
    return 0;
}
