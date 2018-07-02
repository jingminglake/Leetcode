#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int res = 0;
        vector<pair<int, int> > waiting[128];  // first -> index of word, second -> index in word
        for (int i = 0; i < words.size(); i++) {
            waiting[words[i][0]].emplace_back(i, 0);
        }
        for (char c : S) {
            vector<pair<int, int> > words_start_from_c = waiting[c];
            waiting[c].clear();
            for (auto& p : words_start_from_c) {
                if (p.second + 1 == words[p.first].length())
                    res++;
                else
                    waiting[words[p.first][p.second + 1]].emplace_back(p.first, p.second + 1);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    string S = "abcde";
    vector<string> words = {"a", "bb", "acd", "ace"};
    cout << s.numMatchingSubseq(S, words) << endl;
    return 0;
}
