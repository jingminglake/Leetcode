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
        unordered_map<string, vector<string> > path;
        if (!bfs(beginWord, endWord, wordSet, path)) {
            return res;
        }
        vector<string> laddar_path;
        laddar_path.push_back(beginWord);
        dfs(beginWord, endWord, res, laddar_path, path);
        return res;
    }
    bool bfs (string& beginWord, string& endWord, unordered_set<string>& wordSet, unordered_map<string, vector<string> >& path) {
        bool found = false;
        unordered_set<string> q;
        q.insert(beginWord);
        while (!q.empty() && !found) {
            unordered_set<string> next_q;
            for (string word : q) {
                string next_word = word;
                for (int i = 0; i < next_word.length(); i++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == next_word[i])
                            continue;
                        char t = next_word[i];
                        next_word[i] = c;
                        if (!wordSet.count(next_word) || q.count(next_word)) {
                            next_word[i] = t;
                            continue;
                        }
                        if (next_word == endWord) {
                            found = true;
                        }
                        path[word].push_back(next_word);
                        next_q.insert(next_word);
                        next_word[i] = t;
                    }
                }
                wordSet.erase(word);
            } // for
            q.swap(next_q);
            next_q.clear();
        }// while
        return found;
    }
    void dfs (string beginWord, string& endWord, vector<vector<string> >& res, vector<string>& laddar_path, unordered_map<string, vector<string> >& path) {
        if (beginWord == endWord) {
            res.push_back(laddar_path);
            return;
        }
        for (string next : path[beginWord]) {
            laddar_path.push_back(next);
            dfs (next, endWord, res, laddar_path, path);
            laddar_path.pop_back();
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
