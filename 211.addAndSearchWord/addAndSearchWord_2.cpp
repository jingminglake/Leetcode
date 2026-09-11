// clang++ addAndSearchWord.cpp -std=c++11
#include <iostream>
using namespace std;

class TrieNode {
public:
    TrieNode() {
        memset(children, 0, sizeof(children));
        isWord = false;
    }
    ~TrieNode() {
        for (TrieNode* n : children)
            delete n;
    }
    TrieNode* children[26];
    bool isWord;
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    ~WordDictionary() {
        delete root;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.length(); i++) {
            if (cur->children[word[i] - 'a']) {
                cur = cur->children[word[i] - 'a'];
                continue;
            }
            TrieNode *n = new TrieNode();
            cur->children[word[i] - 'a'] = n;
            cur = n;
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(word, 0, root);
    }
    bool dfs(string& word, int index, TrieNode* cur) {
        if (index == word.length()) {
            return cur->isWord;
        }
        char c = word[index];
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (cur->children[i] && dfs(word, index + 1, cur->children[i]))
                    return true;
            }
            return false;
        } else if (!cur->children[c - 'a']) {
            return false;
        } else {
            return dfs(word, index + 1, cur->children[c - 'a']);
        }
    }
    TrieNode* root;
};

int main()
{
    WordDictionary obj;
    obj.addWord("a");
    obj.addWord("aa");
    //obj.addWord("mad");
    cout << obj.search("a") << endl;
    cout << obj.search("aa") << endl;
    cout << obj.search(".a") << endl;
    cout << obj.search("a.") << endl;
    return 0;
}
