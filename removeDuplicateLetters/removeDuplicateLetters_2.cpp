#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> m;
        for (char c : s)
            m[c]++;
        string res;
        unordered_set<char> visited;
        for (char c : s) {
            if (visited.count(c)) {
                m[c]--;
                continue;
            }
            while (!res.empty() && c < res.back() && m[res.back()] > 1) {
                m[res.back()]--;
                visited.erase(res.back());
                res.pop_back();
            }
            res += c;
            visited.insert(c);
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
