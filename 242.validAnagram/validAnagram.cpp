#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> m;
        for (int i = 0; i < s.length(); i++) {
            m[s[i]]++;
            m[t[i]]--;
        }
        for (auto& p : m) {
            if (p.second) return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    string str1 = "anagram";
    string str2 = "nagaram";
    cout << s.isAnagram(str1, str2);
    cout << endl;
    return 0;
}
