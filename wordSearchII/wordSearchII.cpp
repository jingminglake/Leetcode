#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TrieNode {
public:
  TrieNode() : word(""){
    memset(next, 0, sizeof(next));
  }
  ~TrieNode() {
    for (int i = 0; i < 26; i++) {
      if (next[i])
	delete next[i];
    }
  }
  TrieNode *next[26];
  string word;
};
class Solution {
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> res;
    if (board.size() == 0 || words.size() == 0)
      return res;
    TrieNode* node = bulidTrie(words);
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
	dfs(board, node, res, i, j);
      }
    }
    delete node;
    return res;
  }
  TrieNode* bulidTrie(vector<string>& words) {
    TrieNode *root = new TrieNode;
    for (string w : words) {
      TrieNode *p = root;
      for (char c : w) {
	if (!p->next[c - 'a'])
	  p->next[c - 'a'] = new TrieNode;
	p = p->next[c - 'a'];
      }
      p->word = w;
    }
    return root;
  }
  void dfs(vector<vector<char>>& board, TrieNode* node, vector<string>& res, int i, int j) {
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || !node)
      return;
    char c = board[i][j];
    if (c == '#'  || !node->next[c - 'a'])
      return;
    node = node->next[c - 'a'];
    if (node->word != "") {
      res.push_back(node->word);
      node->word = "";
    }
    board[i][j] = '#';
    dfs(board, node, res, i - 1, j);
    dfs(board, node, res, i + 1, j);
    dfs(board, node, res, i, j - 1);
    dfs(board, node, res, i, j + 1);
    board[i][j] = c;
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
