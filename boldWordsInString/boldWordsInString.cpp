#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        string res;
        if (words.size() == 0)
            return res;
        vector<bool> bold(S.length(), false);
        unordered_set<string> wordSet(words.begin(), words.end());
        for (string word : wordSet) {
            markBold(word, bold, S);
        }
        for (int i = 0; i < bold.size(); i++) {
            if (bold[i] && (i == 0 || !bold[i - 1]))
                res += "<b>";
            res += S[i];
            if (bold[i] && (i == S.length() - 1 || !bold[i + 1]))
                res += "</b>";
        }
        return res;
    }
    void markBold(string& word, vector<bool>& bold, string& S) {
        int wordSize = word.length();
        for (int i = 0; i <= (int)S.length() - wordSize; i++) {
            string temp = S.substr(i, wordSize);
            if (word == temp) {
                for (int j = i; j < i + wordSize; j++) {
                    bold[j] = true;
                }
            }
        }
    }
};

int main() {
  vector<string> words = {"ab", "bc"};
  string S = "aabcd";
  Solution s;
  cout << s.boldWords(words, S) << endl;
  return 0;
}
