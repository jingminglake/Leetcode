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
    // bfs from start word
    unordered_map<string, int> steps; // steps from word to beginWord
    unordered_map<string, vector<string> > nexts;
    bfs(beginWord, dict, steps, nexts);
    // dfs
    vector<string> path;
    path.push_back(beginWord);
    dfs(ans, path, beginWord, endWord, steps, nexts);
    return ans;
  }
  void bfs(string beginWord, unordered_set<string>& dict, unordered_map<string, int>& steps, unordered_map<string, vector<string> >& nexts) {
    queue<string> q;
    q.push(beginWord);
    steps[beginWord] = 0;
    while (!q.empty()) {
      string cur = q.front();
      q.pop();
      int curStep = steps[cur];
      for (int i = 0; i < cur.size(); i++) {
	for (char c = 'a'; c <= 'z'; c++) {
	  if (cur[i] == c)
	    continue;
	  string copy = cur;
	  copy[i] = c;
	  if (dict.count(copy) == 0)
	    continue;
	  nexts[cur].push_back(copy);
	  if (!steps.count(copy)) {
	    steps[copy] = curStep + 1;
	    q.push(copy);
	  }
	}
      }
    }
  }
  void dfs(vector<vector<string> >& ans, vector<string>& path, string beginWord, string endWord, unordered_map<string, int>& steps, unordered_map<string, vector<string> >& nexts) {
    if (beginWord == endWord)
      ans.push_back(path);
    else {
      int step = steps[beginWord];
      for (string next : nexts[beginWord]) {
	if (steps[next] != step + 1)
	  continue;
	path.push_back(next);
	dfs(ans, path, next, endWord, steps, nexts);
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
