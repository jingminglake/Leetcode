#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int left = 0, right = 0;
        unordered_set<char> char_set;
        while (right < s.length()) {
            if (!char_set.count(s[right])) {
                char_set.insert(s[right]);
                right++;
            } else {
                char_set.erase(s[left]);
                left++;
            }
            res = max (res, right - left);
        }
        return res;
    }
};



int main()
{
    string s = "pwwkew";
    Solution sl;
    cout << sl.lengthOfLongestSubstring(s) << endl;
}
