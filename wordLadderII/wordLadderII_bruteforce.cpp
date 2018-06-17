// Time Limit Exceeded

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string> > res;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord))
            return res;
        int len = 0;
        unordered_set<string> visited;
        if (!bfs(beginWord, endWord, wordSet, visited, len)) {
            return res;
        }
        vector<string> path;
        path.push_back(beginWord);
        visited.clear();
        dfs(0, beginWord, endWord, wordSet, res, path, len, visited);
        return res;
    }
    bool bfs (string& beginWord, string& endWord, unordered_set<string>& wordSet, unordered_set<string>& visited, int& len) {
        bool found = false;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        while (!q.empty() && !found) {
            int size = q.size();
            len++;
            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();
                string next_word = word;
                for (int i = 0; i < next_word.length(); i++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == next_word[i])
                            continue;
                        char t = next_word[i];
                        next_word[i] = c;
                        if (!wordSet.count(next_word) || visited.count(next_word)) {
                            next_word[i] = t;
                            continue;
                        }
                        if (next_word == endWord) {
                            return len + 1;
                        }
                        visited.insert(next_word);
                        q.push(next_word);
                        next_word[i] = t;
                    }
                }
            }
        }// while
        return found;
    }
    void dfs (int level, string beginWord, string& endWord, unordered_set<string>& wordSet, vector<vector<string> >& res, vector<string>& path, int& len, unordered_set<string>& visited) {
        if (level == len) {
            if (beginWord == endWord)
                res.push_back(path);
            return;
        }
        for (int i = 0; i < beginWord.length(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == beginWord[i])
                    continue;
                char t = beginWord[i];
                beginWord[i] = c;
                if (!wordSet.count(beginWord) || visited.count(beginWord)) {
                    beginWord[i] = t;
                    continue;
                }
                path.push_back(beginWord);
                visited.insert(beginWord);
                dfs (level + 1, beginWord, endWord, wordSet, res, path, len, visited);
                path.pop_back();
                visited.erase(beginWord);
                beginWord[i] = t;
            }
        }
    }
};

int main()
{
    Solution s;
    string beginWord = "red";
    string endWord = "tax";
    vector<string> wordList = {"ted","tex","red","tax","tad","den","rex","pee"};
    vector<vector<string> > res = s.findLadders(beginWord, endWord, wordList);
    for (auto& vec : res) {
        for (const string& ss : vec)
            cout << ss << " ";
        cout << endl;
    }
    return 0;
}
