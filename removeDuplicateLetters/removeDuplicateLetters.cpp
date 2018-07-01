#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res;
        if (s.length() < 2)
            return s;
        int remain[26] = {0};
        for (char c : s)
            remain[c - 'a']++;
        bool visited[26] = {false};
        for (int i = 0; i < s.length(); i++) {
            remain[s[i] - 'a']--;
            if (visited[s[i] - 'a'])
                continue;
            while (!res.empty() && s[i] < res.back() && remain[res.back() - 'a']) {
                visited[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(s[i]);
            visited[s[i] - 'a'] = true;
        }
        return res;
    }
};

int main() {
    Solution s;
    string ss = "cbacdcbc";
    cout << s.removeDuplicateLetters(ss);
    cout << endl;
    return 0;
}
