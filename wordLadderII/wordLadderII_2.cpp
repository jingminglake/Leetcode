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
        if (beginWord == endWord)
            return res;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord))
            return res;
        unordered_map<string, vector<string> > children;
        if (bfs(beginWord, endWord, wordSet, children)) {
            vector<string> path;
            path.push_back(beginWord);
            dfs(beginWord, endWord, res, children, path);
        }
        return res;
    }
    bool bfs(string& beginWord, string& endWord, unordered_set<string>& wordSet, unordered_map<string, vector<string> >& children) {
        unordered_set<string> s;
        s.insert(beginWord);
        bool find = false;
        while (!s.empty() && !find) {
            unordered_set<string> next_layer;
            for (string word : s) {
                string word_copy = word;
                for (int i = 0; i < word.length(); i++) {
                    char cur = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == cur)
                            continue;
                        word[i] = c;
                        if (wordSet.count(word) && !s.count(word)) {
                            next_layer.insert(word);
                            children[word_copy].push_back(word);
                            if (word == endWord)
                                find = true;
                        }
                    } // for
                    word[i] = cur;
                } // for
                wordSet.erase(word_copy);
            } // for
            s.swap(next_layer);
        }
        return find;
    } // bfs
    void dfs(string begin, string& end, vector<vector<string> >& res, unordered_map<string, vector<string> >& children, vector<string>& path) {
        if (begin == end) {
            res.push_back(path);
            return;
        }
        for (string word : children[begin]) {
            path.push_back(word);
            dfs(word, end, res, children, path);
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
