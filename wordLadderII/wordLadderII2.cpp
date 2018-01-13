#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution{
public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string> > ans;
    unordered_set<string> dict;
    for (string& word : wordList)
      dict.insert(word);
    if (!dict.count(endWord))
      return ans;
    // bfs from start word
    unordered_map<string, vector<string> > nexts;
    bool found = bfs(beginWord, endWord, dict, nexts);
    // dfs
    vector<string> path;
    if (found) {
      path.push_back(beginWord);
      dfs(ans, path, beginWord, endWord, nexts);
    }
    return ans;
  }
  bool bfs(string beginWord, string endWord, unordered_set<string>& dict, unordered_map<string, vector<string> >& nexts) {
    bool found = false;
    unordered_set<string> q;
    q.insert(beginWord);
    while (!q.empty() && !found) {
      unordered_set<string> p;
      for (const string& word : q)
	dict.erase(word);

      for (const string& cur : q) {
	for (int i = 0; i < cur.size(); i++) {
	  for (char c = 'a'; c <= 'z'; c++) {
	    if (cur[i] == c)
	      continue;
	    string copy = cur;
	    copy[i] = c;
	    if (copy == endWord) {
	      found = true;
	      nexts[cur].push_back(copy);
	    } else if (dict.count(copy) && !found) {
	      p.insert(copy);
	      nexts[cur].push_back(copy);
	    }
	  }
	}
      }
      swap (p, q);
    }// while
    return found;
  }
  void dfs(vector<vector<string> >& ans, vector<string>& path, string beginWord, string endWord, unordered_map<string, vector<string> >& nexts) {
    if (beginWord == endWord) {
      ans.push_back(path);
      return;
    }
    if (nexts.count(beginWord) == 0)
      return;
    else {
      for (string next : nexts[beginWord]) {
	path.push_back(next);
	dfs(ans, path, next, endWord, nexts);
	path.pop_back();
      }
    }
  }
};

int main()
{
  Solution s;
  string beginWord = "hit";
  string endWord = "cog";
  vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
  vector<vector<string> > res = s.findLadders(beginWord, endWord, wordList);
  for (auto& vec : res) {
    for (const string& ss : vec)
      cout << ss << " ";
    cout << endl;
  }
  return 0;
}
