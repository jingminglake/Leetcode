#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    class TrieNode {
    public:
        TrieNode() {
            memset(next, 0, sizeof(next));
            word = "";
        }
        ~TrieNode() {
            for (TrieNode* t : next)
                delete t;
        }
        TrieNode* next[26];
        string word;
    };
    void add (string& word) {
        TrieNode *cur = root;
        for (char c : word) {
            if (!cur->next[c - 'a'])
                cur->next[c - 'a'] = new TrieNode;
            cur = cur->next[c - 'a'];
        }
        cur->word = word;
    }
    void dfs(TrieNode* node, vector<string>& res, int i, int j, vector<vector<char> >& board, vector<pair<int, int> >& dirs) {
        if (node->word.size()) {
            res.push_back(node->word);
            node->word = "";
        }
        for (auto& dir : dirs) {
            int next_i = i + dir.first;
            int next_j = j + dir.second;
            if (next_i < 0 || next_i >= board.size() || next_j < 0 || next_j >= board[0].size() || board[next_i][next_j] == '#')
                continue;
            char c = board[next_i][next_j];
            if (node->next[c - 'a']) {
                board[next_i][next_j] = '#';
                dfs(node->next[c - 'a'], res, next_i, next_j, board, dirs);
                board[next_i][next_j] = c;
            }
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (board.size() == 0 || board[0].size() == 0 || words.size() == 0)
            return res;
        int m = board.size(), n = board[0].size();
        root = new TrieNode();
        for (string& word : words)
            add(word);
        vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = board[i][j];
                if (root->next[c - 'a']) {
                    board[i][j] = '#';
                    dfs(root->next[c - 'a'], res, i, j, board, dirs);
                    board[i][j] = c;
                }
            }
        }
        delete root;
        return res;
    }
    TrieNode* root;
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
