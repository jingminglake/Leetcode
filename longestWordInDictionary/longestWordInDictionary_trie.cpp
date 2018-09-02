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
            is_word = false;
        }
        TrieNode* next[26];
        string word;
        bool is_word;
    };
    string longestWord(vector<string>& words) {
        root = new TrieNode();
        for (string& word : words)
            addWord(word);
        string res;
        getLongestWord(root, res);
        return res;
    }
    void addWord(string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->next[c - 'a'])
                cur->next[c - 'a'] = new TrieNode();
            cur = cur->next[c - 'a'];
        }
        cur->is_word = true;
        cur->word = word;
    }
    void getLongestWord(TrieNode* root, string& res) {
        for (TrieNode* n : root->next) {
            if (n && n->is_word) {
                if (n->word.size() > res.size())
                    res = n->word;
                getLongestWord(n, res);
            }
        }
    }
    TrieNode* root;
};

int main()
{
  Solution s;
  vector<string> words = {"a","banana", "app", "appl", "ap", "apply", "apple"};
  cout << s.longestWord(words) << endl;
  return 0;
}
