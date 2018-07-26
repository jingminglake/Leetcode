#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int min_len = INT_MAX;
        if (s.length() < t.length())
            return "";
        unordered_map<char, int> m;
        for (char c : t)
            m[c]++;
        int left = 0, right = 0, start = 0;
        int count = t.length();
        while (right < s.length()) {
            if (m.count(s[right]) && m[s[right]]-- > 0)
                count--;
            right++;
            while (count == 0) {
                if (right - left < min_len) {
                    start = left;
                    min_len = right - left;
                }
                if (m.count(s[left])) {
                    if (++m[s[left]] > 0)
                        count++;
                }
                left++;
            }
        }
        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};

int main()
{
    Solution s;
    string S = "ADOBECODEBANC";
    string T = "ABC";
    cout << s.minWindow(S, T) << endl;
    return 0;
}
