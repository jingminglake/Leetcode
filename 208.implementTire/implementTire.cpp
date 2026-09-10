// clang++ implementTire.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    TrieNode() {
        memset(next, 0, sizeof(next));
        isWord = false;
    }
    ~TrieNode() {
        for (int i = 0; i < 26; i++) {
            if (next[i]) delete next[i];
        }
    }
    TrieNode* next[26];
    bool isWord;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *cur = root;
        for (char c : word) {
            if (!cur->next[c - 'a']) cur->next[c - 'a'] = new TrieNode();
            cur = cur->next[c - 'a'];
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *cur = find(word);
        return cur && cur->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }
    
    TrieNode* find(string& k) {
        TrieNode* t = root;
        for (char c : k) {
            if (t) t = t->next[c - 'a'];
            else break;
        }
        return t;
    }
    TrieNode* root;
};


int main()
{
    Trie obj;
    string word = "but";
    obj.insert(word);
    bool param_2 = obj.search("bu");
    cout << param_2 << endl;
    string prefix = "b";
    bool param_3 = obj.startsWith("b");
    cout << param_3 << endl;
    return 0;
}
