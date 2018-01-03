#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution{
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int res = 0;
    unordered_set<string> s;
    for (string& word : wordList)
      s.insert(word);
    if (!bfs(beginWord, endWord, s, res)) {
      res = 0;
    }
    return res;
  }
  bool bfs(string beginWord, string endWord, unordered_set<string>& s, int& res) {
    res++;
    unordered_set<string> start, end;
    start.insert(beginWord);
    end.insert(endWord);
    while (!start.empty() && !end.empty()) {
      if (start.size() < end.size())
	start.swap(end);
      unordered_set<string> temp;
      int size = start.size();
      res++;
      for (string word : start) {
	for (int m = 0; m < word.size(); m++)
	  for (int n = 0; n < 26; n++) {
	    string next = word;
	    if ('a' + n == next[m])
	      continue;
	    next[m] = 'a' + n;
	    if ( s.count(next) ) {
	      if ( end.count(next) )
		return true;
	      temp.insert(next);
	      s.erase( s.find(next) );
	    }
	  }
      }
      start = temp;
    }
    return false;
  }
};

int main()
{
  Solution s;
  string beginWord = "hit";
  string endWord = "cog";
  vector<string> wordList = {"hot", "dot", "lot", "log", "cog"};
  cout << s.ladderLength(beginWord, endWord, wordList) << endl;
  return 0;
}
