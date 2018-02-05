// clang++ addAndSearchWord.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
  TrieNode() : isWord(false) {
    memset(next, 0, sizeof(next));
  }
  ~TrieNode() {
    for (TrieNode *t : next) {
      if (t)
	delete t;
    }
  }
  TrieNode* next[26];
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
    for (char c : word) {
      if (!cur->next[c - 'a']) {
	cur->next[c - 'a'] = new TrieNode();
      }
      cur = cur->next[c - 'a'];
    }
    cur->isWord = true;
  }
    
  /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
  bool search(string word) {
    return searchHelper(word, root);
  }
  bool searchHelper(string word, TrieNode* cur) {
    for (int i = 0; i < word.size(); i++) {
      if (!cur)
	return false;
      if (word[i] == '.') {
	string remain = word.substr(i + 1);
	for (TrieNode *t : cur->next) {
	  if (searchHelper(remain, t))
	    return true;
	}
	return false;
      } else {
	cur = cur->next[word[i] - 'a'];
      }
    }
    return cur && cur->isWord;
  }
  TrieNode *root;
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
