#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        int len_s = S.length();
        vector<bool> bold(len_s, false);
        for (string& word : words) {
            int word_len = word.length();
            size_t pos = S.find(word);
            while (pos != string::npos) {
                for (int i = pos; i < pos + word_len; i++) bold[i] = true;
                pos = S.find(word, pos + 1);
            }
        }
        string res;
        for (int i = 0; i < len_s; i++) {
            if (bold[i] && (i == 0 || !bold[i - 1]))
                res += "<b>";
            res += S[i];
            if (bold[i] && (i == len_s - 1 || !bold[i + 1]))
                res += "</b>";
        }
        return res;
    }
};

int main() {
    vector<string> words = {"ab", "bc"};
    string S = "aabcd";
    Solution s;
    cout << s.boldWords(words, S) << endl;
    return 0;
}
