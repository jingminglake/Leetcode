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
        unordered_map<string, vector<string> > bfsTree;
        vector<string> path;
        if (bfs(beginWord, endWord, bfsTree, wordSet)) {
            path.push_back(beginWord);
            dfs(beginWord, endWord, bfsTree, path, res);
        }
        return res;
    }
    bool bfs(string& beginWord, string& endWord, unordered_map<string, vector<string> >& bfsTree, unordered_set<string>& wordSet) {
        unordered_set<string> q;
        q.insert(beginWord);
        bool found = false;
        while (!q.empty() && !found) {
            unordered_set<string> next;
            for (string word : q) {
                string word_copy = word;
                for (int k = 0; k < word.length(); k++) {
                    char t = word[k];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == t)
                            continue;
                        word[k] = c;
                        if (q.count(word))
                            continue;
                        if (wordSet.count(word)) {
                            if (word == endWord) {
                                found = true;
                            }
                            next.insert(word);
                            bfsTree[word_copy].push_back(word);
                        }
                    }
                    word[k] = t;
                }// for
                wordSet.erase(word);
            }// for
            q.swap(next);
        }
        return found;
    }
    void dfs(string& beginWord, string& endWord, unordered_map<string, vector<string> >& bfsTree, vector<string>& path, vector<vector<string> >& res) {
        if (beginWord == endWord) {
            res.push_back(path);
            return;
        }
        for (string& next : bfsTree[beginWord]) {
            path.push_back(next);
            dfs(next, endWord, bfsTree, path, res);
            path.pop_back();
        }
    }
};

int main()
{
    Solution s;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string> > res = s.findLadders(beginWord, endWord, wordList);
    for (auto& vec : res) {
        for (const string& ss : vec)
            cout << ss << " ";
        cout << endl;
    }
    return 0;
}
