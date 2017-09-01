// clang++ addAndSearchWord.cpp -std=c++11

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class TrieNode {
public:
  TrieNode *next[26];
  bool isWord;
  TrieNode() : isWord(false){
    memset(next, 0, sizeof(TrieNode *) * 26);
  }
};

class WordDictionary {
public:
  /** Initialize your data structure here. */
  WordDictionary() {
    root = new TrieNode();
  }
    
  /** Inserts a word into the data structure. */
  void addWord(string word) {
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
    return find(word, root);
  }
    
  ~WordDictionary() {
    delete root;
  }
private:
 bool find(string& key, TrieNode* r) {
    TrieNode *p = r;// TrieNode must find start from p
    int size = key.length();
    for (int i = 0; i < size; i++) {
      if (!p)
	break;
      if (key[i] == '.') {
	string remain = key.substr(i+1);
	TrieNode *t = p;
	for (int j = 0; j < 26; j++) {
	  p = t->next[j];
	  if (find(remain, p))
	    return true;
	}
      } else {
	p = p->next[key[i] - 'a'];
      }
    }
    return p && p->isWord;
  }
  TrieNode *root;
};

int main()
{
  WordDictionary obj;
  obj.addWord("a");
  // obj.addWord("a");
  //obj.addWord("mad");
  cout << obj.search("a") << endl;
  cout << obj.search("aa") << endl;
  cout << obj.search(".a") << endl;
  cout << obj.search("a.") << endl;
  return 0;
}
