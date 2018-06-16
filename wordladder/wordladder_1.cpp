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
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;
        while (!q.empty()) {
            res++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string cur = q.front();
                q.pop();
                string next = cur;
                for (int m = 0; m < cur.length(); m++) {
                    for (int n = 0; n < 26; n++) {
                        char c = next[m];
                        if (c == n + 'a')
                            continue;
                        next[m] = n + 'a';
                        if (next == endWord) {
                            return res + 1;
                        }
                        if (wordSet.count(next) && !visited.count(next)) {
                            visited.insert(next);
                            q.push(next);
                        }
                        next[m] = c;
                    }
                }
            }         
        }// while
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
