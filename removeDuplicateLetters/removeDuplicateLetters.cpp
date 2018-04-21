#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res = "0";
        unordered_map<char, int> m;
        unordered_map<char, bool> visited;
        for (char c : s)
            m[c]++;
        for (char c : s) {
            m[c]--;
            if (visited[c])
                continue;
            while (c < res.back() && m[res.back()]) {
                visited[res.back()] = false;
                res.pop_back();
            }
            res += c;
            visited[c] = true;
        }
        return res.substr(1);
    }
};

int main() {
    Solution s;
    string ss = "cbacdcbc";
    cout << s.removeDuplicateLetters(ss);
    cout << endl;
    return 0;
}
