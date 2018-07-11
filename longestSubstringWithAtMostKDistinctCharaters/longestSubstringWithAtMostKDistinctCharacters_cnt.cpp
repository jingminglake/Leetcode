#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int res = 0;
        int left = 0, right = 0;
        unordered_map<char, int> m;
        while (right < s.length()) {
            m[s[right]]++;
            right++;
            while (m.size() > k) {
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
    int k = 2;
    cout << s.lengthOfLongestSubstringKDistinct(str1, k) << endl;
    cout << s.lengthOfLongestSubstringKDistinct(str2, k) << endl;
    return 0;
}
