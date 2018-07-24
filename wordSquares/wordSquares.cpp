#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    class TrieNode {
    public:
        TrieNode(){
            memset(next, 0, sizeof(next));
        }
        ~TrieNode() {
            for (int i = 0; i < 26; i++)
                delete next[i];
        }
        TrieNode *next[26];
        vector<string> startWith;
    };
    void addWord(string& word) {
        TrieNode *cur = root;
        for (char c : word) {
            if (!cur->next[c - 'a'])
                cur->next[c - 'a'] = new TrieNode();
            cur->next[c - 'a']->startWith.push_back(word);
            cur = cur->next[c - 'a'];
        }
    }
    vector<vector<string> > wordSquares(vector<string>& words) {
        vector<vector<string> > res;
        if (words.size() == 0)
            return res;
        root = new TrieNode();
        for (string& word : words) {
            addWord(word);
        }
        vector<string> path;
        for (string& word : words) {  // first word do not have pre word, so add first
            path.push_back(word);
            dfs(1, words, path, res);
            path.pop_back();
        }
        delete root;
        return res;
    }
    vector<string> getStartWith(string& prefix) {
        TrieNode *cur = root;
        for (char c : prefix) {
            if (!cur->next[c - 'a'])
                return vector<string>();
            cur = cur->next[c - 'a'];
        }
        return cur->startWith;
    }
    void dfs(int i, vector<string>& words, vector<string>& path, vector<vector<string> >& res) {
        if (i == words[0].size()) {
            res.push_back(path);
            return;
        }
        string prefix;
        for (int k = 0; k < i; k++)
            prefix += path[k][i];
        for (string& word : getStartWith(prefix)) {
            path.push_back(word);
            dfs(i + 1, words, path, res);
            path.pop_back();
        }
    }
    TrieNode *root;
};

int main() {
    Solution s;
    vector<string> words = {"area","lead","wall","lady","ball"};
    for (auto& vec : s.wordSquares(words)) {
        for (string& w : vec)
            cout << w << " ";
        cout << endl;
    }
    return 0;
}
