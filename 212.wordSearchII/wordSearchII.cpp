#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TrieNode {
public:
    TrieNode() : word("") {
        memset(next, 0, sizeof(next));
    }
    ~TrieNode() {
        for (TrieNode* t : next)
            delete t;
    }
    TrieNode* next[26];
    string word;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (board.size() == 0 || board[0].size() == 0)
            return res;
        int m = board.size(), n = board[0].size();
        root = new TrieNode();
        for (string& word : words)
            add(word);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, root, i, j, res);
            }
        }
        delete root;
        return res;
    }
    void dfs(vector<vector<char>>& board, TrieNode* cur_root, int i, int j, vector<string>& res) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '#')
            return;
        char c = board[i][j];
        TrieNode* next_root = cur_root->next[c - 'a'];
        if (!next_root)
            return;
        if (next_root->word != "") {
            res.push_back(next_root->word);
            next_root->word = "";
        }
        board[i][j] = '#';
        dfs(board, next_root, i + 1, j, res);
        dfs(board, next_root, i - 1, j, res);
        dfs(board, next_root, i, j + 1, res);
        dfs(board, next_root, i, j - 1, res);
        board[i][j] = c;
    }
    TrieNode *root;
    void add(string& word) {
        TrieNode *cur = root;
        for (char c : word) {
            if (!cur->next[c - 'a'])
                cur->next[c - 'a'] = new TrieNode();
            cur = cur->next[c - 'a'];
        }
        cur->word = word;
    }
};

int main()
{
    Solution s;
    vector<vector<char> > board = { {'o','a','a','n'},
                                    {'e','t','a','e'},
                                    {'i','h','k','r'},
                                    {'i','f','l','v'},};
    vector<string> words = {"oath","pea","eat","rain"};
    for (string ss : s.findWords(board, words))
        cout << ss << endl;
    return 0;
}
