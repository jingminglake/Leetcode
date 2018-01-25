// clang++ implementTire.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
  TrieNode *next[26];
  bool isWord;
  TrieNode() : isWord(false){
    memset(next, 0, sizeof(next));
  }
  ~TrieNode(){
    for (int i = 0; i < 26; i++) {
      if (next[i])
	delete next[i];
    }
  }
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
    TrieNode *p = root;
    for (int i = 0; i < word.size(); i++) {
      if (p->next[word[i]- 'a'] == NULL)
	p->next[word[i] - 'a'] = new TrieNode();
      p = p->next[word[i] - 'a'];
    }
    p->isWord = true;
  }
    
  /** Returns if the word is in the trie. */
  bool search(string word) {
    TrieNode *t = find(word);
    return t != NULL && t->isWord;
  }
    
  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
    TrieNode *t = find(prefix);
    return t != NULL;
  }
private:
  TrieNode * find(string& key) {
    TrieNode *p = root;
    for (int i = 0; i < key.size(); i++) {
      if (p)
	p = p->next[key[i] - 'a'];
      else
	break;
    }
    return p;
  }
  TrieNode *root;
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
