// clang++ replaceWords.cpp -std=c++11

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
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
    
  /** Returns if the word is in the trie. */
  bool search(string word) {
    return find(word, root);
  }
  string replaceWords(vector<string>& dict, string sentence) {
    string res;
    for (string &word : dict) {
      addWord(word);
    }
    istringstream iss(sentence);
    string word;
    while (getline(iss, word, ' ')) {
      replace(word);
      res += word + " ";
    }
    res.pop_back();
    return res;
  }

  void replace(string& word) {
    string res;
    bool exists = find2(word, root, res);
    if (exists) {
      word = res;
    }
  }
    
  ~WordDictionary() {
    delete root;
  }
private:
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
  bool find2(string& key, TrieNode* r, string &res) {
    TrieNode *p = r;// TrieNode must find start from p
    int size = key.length();
    for (int i = 0; i < size; i++) {
      if (!p || p->isWord)
	break;
      p = p->next[key[i] - 'a'];
      if (p)
	res += key[i];
    }
    return p && p->isWord;
  }
  TrieNode *root;
};

int main()
{
  WordDictionary obj;
  vector<string> dict = {"cat", "bat", "rat"};
  string sentence = "the cattle was rattled by the battery";
  cout << obj.replaceWords(dict, sentence) << endl;
  return 0;
}
