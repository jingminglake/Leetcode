#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;
        unordered_map<char, char> m;
        unordered_set<char> used;
        for (int i = 0; i < s.length(); i++) {
            if (!m.count(s[i]) && !used.count(t[i])) {
                m[s[i]] = t[i];
                used.insert(t[i]);
            } else {
                if (m[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    string str1 = "aba";
    string str2 = "baa";
    cout << s.isIsomorphic(str1, str2);
    cout << endl;
    return 0;
}
