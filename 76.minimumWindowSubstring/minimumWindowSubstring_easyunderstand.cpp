#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length())
            return "";
        unordered_map<char, int> hash_t;
        for (char c : t)
            hash_t[c]++;
        int count = t.length();
        int left = 0, right = 0;
        int min_len = s.length() + 1, start_index = -1;
        while (right < s.length()) {
            if (hash_t.count(s[right]) && hash_t[s[right]]-- > 0)
                count--;
            right++;
            while (count == 0) {
                if (right - left < min_len) {
                    min_len = right - left;
                    start_index = left;
                }
                if (hash_t.count(s[left]) && ++hash_t[s[left]] > 0)
                    count++;
                left++;
            }
        } // while
        return start_index != -1 ? s.substr(start_index, min_len) : "";
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
