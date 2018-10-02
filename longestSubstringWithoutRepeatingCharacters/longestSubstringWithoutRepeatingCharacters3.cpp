#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        if (s.length() == 0)
            return res;
        int left = 0, right = 0;
        unordered_map<char, int> m;
        while (right < s.length()) {
            if (m.count(s[right])) {
                left = max(left, m[s[right]] + 1);
            }
            m[s[right]] = right;
            res = max (res, right - left + 1);
            right++;
        }
        return res;
    }
};

int main()
{
    string s;
    cout << "please input a string:" << endl;
    cin >> s;
    Solution sl;
    cout << sl.lengthOfLongestSubstring(s) << endl;
}
