#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        int len_s = s.length();
        vector<bool> bold(len_s, false);
        for (string& word : dict) {
            int word_len = word.length();
            size_t pos = s.find(word);
            while (pos != string::npos) {
                for (int i = pos; i < pos + word_len; i++) bold[i] = true;
                pos = s.find(word, pos + 1);
            }
        }
        string res;
        for (int i = 0; i < len_s; i++) {
            if (bold[i] && (i == 0 || !bold[i - 1]))
                res += "<b>";
            res += s[i];
            if (bold[i] && (i == len_s - 1 || !bold[i + 1]))
                res += "</b>";
        }
        return res;
    }
};

int main() {
    Solution s;
    string str = "abcxyz123";
    vector<string> dict = {"abc","123"};
    cout << s.addBoldTag(str, dict) << endl;
    return 0;
}
