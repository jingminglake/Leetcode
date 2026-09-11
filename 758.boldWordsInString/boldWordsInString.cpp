#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        int len_s = S.length();
        vector<bool> bold(len_s, false);
        int end = -1;
        for (int i = 0; i < len_s; i++) {
            for (string& word : words) {
                if (word == S.substr(i, word.length())) 
                    end = max (end, i + (int)word.length());
            }
            bold[i] = end > i;
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
