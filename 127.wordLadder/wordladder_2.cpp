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
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()) {
            int size = q.size();
            res++;
            for (int i = 0; i < size; i++) {
                string word = q.front(); q.pop();
                for (int j = 0; j < word.length(); j++) {
                    string next_word = word;
                    char origin = next_word[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == origin) continue;
                        next_word[j] = c;
                        if (wordSet.count(next_word)) {
                            if (next_word == endWord) return res + 1;
                            q.push(next_word);
                            wordSet.erase(next_word);
                        }
                    }
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
