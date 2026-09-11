#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (beginWord == endWord || !wordSet.count(endWord))
            return 0;
        unordered_set<string> start, end;
        start.insert(beginWord);
        end.insert(endWord);
        int res = 0;
        while (!start.empty() && !end.empty()) {
            if (start.size() > end.size())
                start.swap(end);
            res++;
            unordered_set<string> next_s;
            for (string word : start) {
                for (int i = 0; i < word.length(); i++) {
                    char t = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == t)
                            continue;
                        word[i] = c;
                        if (end.count(word))
                            return res + 1;
                        if (wordSet.count(word)) {
                            next_s.insert(word);
                            wordSet.erase(word);
                        }
                    }
                    word[i] = t;
                }
            }
            start = next_s;
        }
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
