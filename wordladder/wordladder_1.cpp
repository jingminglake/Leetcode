#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (beginWord == endWord || !wordSet.count(endWord))
            return 0;
        queue<string> q;
        q.push(beginWord);
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            res++;
            for (int k = 0; k < size; k++) {
                string word = q.front();
                q.pop();
                for (int i = 0; i < word.length(); i++) {
                    char t = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == t)
                            continue;
                        word[i] = c;
                        if (word == endWord)
                            return res + 1;
                        if (wordSet.count(word)) {
                            q.push(word);
                            wordSet.erase(word);
                        }
                    }
                    word[i] = t;
                }
            }
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
