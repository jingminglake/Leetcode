#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int res = 0;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord) || beginWord == endWord)
            return res;
        unordered_set<string> start, end;
        start.insert(beginWord);
        end.insert(endWord);
        while (!start.empty() && !end.empty()) {
            if (start.size() > end.size())
                start.swap(end);
            res++;
            unordered_set<string> next;
            for (string word : start) {
                for (int i = 0; i < word.length(); i++) {
                    for (int j = 0; j < 26; j++) {
                        char c = word[i];
                        if (c == 'a' + j)
                            continue;
                        word[i] = 'a' + j;
                        if (!wordSet.count(word)) {
                            word[i] = c;
                            continue;
                        }
                        if (end.count(word))
                            return res + 1;
                        next.insert(word);
                        word[i] = c;
                    }
                } // for
                wordSet.erase(word);
            }// for
            start = next;
        }//while
        return 0;
    }
};

int main()
{
    Solution s;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "lot", "log", "cog"};
    cout << s.ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}
