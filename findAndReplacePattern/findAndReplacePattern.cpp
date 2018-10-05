#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (string& word : words) {
            int len_w = word.length();
            int len_p = pattern.length();
            if (len_w != len_p)
                continue;
            unordered_map<char, char> w2p;
            unordered_map<char, char> p2w;
            bool flag = true;
            for (int i = 0; i < len_w; i++) {
                char c = word[i];
                char p = pattern[i];
                if (w2p.count(c) && p2w.count(p)) {
                    if (w2p[c] != pattern[i] || p2w[pattern[i]] != c) {
                        flag = false;
                        break;
                    }
                } else if (!w2p.count(c) && !p2w.count(p)) {
                     w2p[c] = pattern[i];
                     p2w[pattern[i]] = c;
                } else {
                    flag = false;
                    break;
                }
            }
            if (flag)
                res.push_back(word);
        }
        return res;
    }
};

int main () {
    Solution s;
    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    string pattern = "abb";
    for (string w : s.findAndReplacePattern(words, pattern)) {
        cout << w << " ";
    }
    cout << endl;
    return 0;
}
