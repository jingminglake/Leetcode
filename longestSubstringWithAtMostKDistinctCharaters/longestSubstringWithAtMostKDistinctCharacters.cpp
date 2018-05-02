#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int res = 0;
        if (k == 0 || s.length() == 0)
            return res;
        unordered_map<char, int> m;
        int left = 0, right = 0;
        while (right < s.length()) {
            m[s[right]] = right;
            right++;
            if (m.size() > k) {
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
    int k = 2;
    cout << s.lengthOfLongestSubstringKDistinct(str1, k) << endl;
    cout << s.lengthOfLongestSubstringKDistinct(str2, k) << endl;
    return 0;}
