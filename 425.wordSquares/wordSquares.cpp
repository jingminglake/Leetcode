#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode() {
        memset(next, 0, sizeof(next));
    }
    ~TrieNode() {
        for (TrieNode* t : next)
            delete t;
    }
    TrieNode* next[26];
    vector<int> word_indexes;
};
class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string> > res;
        if (words.size() == 0)
            return res;
        root = new TrieNode();
        for (int i = 0; i < words.size(); i++)
            add(words, i);
        vector<string> path;
        for (string& word : words) {
            path.push_back(word);
            dfs(1, words, path, res);
            path.pop_back();
        }
        delete root;
        return res;
    }
    void dfs(int i, vector<string>& words, vector<string>& path, vector<vector<string> >& res) {
        if (i == words[0].size()) {
            res.push_back(path);
            return;
        }
        string prefix;
        for (int j = 0; j < i; j++) {
            prefix += path[j][i];
        }
        for (int word_index : getWordIndexes(prefix)) {
            path.push_back(words[word_index]);
            dfs (i + 1, words, path, res);
            path.pop_back();
        }
    }
    TrieNode *root;
    void add(vector<string>& words, int index) {
        TrieNode* cur = root;
        for (char c : words[index]) {
            cur->word_indexes.push_back(index);
            if (!cur->next[c - 'a'])
                cur->next[c - 'a'] = new TrieNode();
            cur = cur->next[c - 'a'];
        }
    }
    vector<int> getWordIndexes(string& prefix) {
        TrieNode *cur = root;
        for (char c : prefix) {
            if (!cur->next[c - 'a'])
                return vector<int>();
            cur = cur->next[c - 'a'];
        }
        return cur->word_indexes;
    }
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
