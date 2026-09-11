#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0;
        int left = 0, right = 0;
        unordered_map<char, int> m;
        while (right < s.length()) {
            m[s[right]]++;
            right++;
            while (m.size() > 2) {
                if (--m[s[left]] == 0)
                    m.erase(s[left]);
                left++;
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
