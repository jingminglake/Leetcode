// time complexity O(mn)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        int min_len = INT_MAX;
        if (s.length() < t.length())
            return res;
        unordered_map<char, int> hash_t;
        for (char c : t)
            hash_t[c]++;
        int left = 0, right = 0;
        unordered_map<char, int> hash_s;
        while (left < s.length()) {
            while (right < s.length() && !isCover(hash_t, hash_s) ) {
                if (!hash_t.count(s[right])) {
                    right++;
                    continue;
                }
                hash_s[s[right]]++;
                right++;
            }
            if (isCover(hash_t, hash_s)) {
                if (right - left < min_len) {
                    res = s.substr(left, right - left);
                    min_len = right - left;
                }
            }
            hash_s[s[left]]--;
            left++;
        }
        return res;
    }
    bool isCover(unordered_map<char, int>& hash_t, unordered_map<char, int>& hash_s) {
        for (auto& p : hash_t) {
            if (!hash_s.count(p.first) || p.second > hash_s[p.first])
                return false;
        }
        return true;
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
