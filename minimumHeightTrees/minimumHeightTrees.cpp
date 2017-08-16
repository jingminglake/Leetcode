#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution{
public:
  vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
    vector<int> res;
    if (n == 1) {
      res.push_back(0);
      return res;
    }
    vector<unordered_set<int> > adj(n);
    queue<int> q;
    for (pair<int, int>& edge : edges) {
      adj[edge.first].insert(edge.second);
      adj[edge.second].insert(edge.first);
    }
    for (int i = 0; i < n; i++) {
      if (adj[i].size() == 1)
	q.push(i);
    }
    while (n > 2) {
      int size = q.size();
      n -= size;
      for (int i = 0; i < size; i++) {
	int leaf = q.front();
	q.pop();
	for (int k : adj[leaf]) {
	  adj[k].erase(leaf);
	  if (adj[k].size() == 1)
	    q.push(k);
	}
      }
    }//while
    while (!q.empty()) {
      res.push_back(q.front());
      q.pop();
    }
    return res;
  }
};

int main()
{
  Solution s;
  vector<pair<int, int> > edges;
  edges.push_back(make_pair(0,3));
  edges.push_back(make_pair(1,3));
  edges.push_back(make_pair(2,3));
  edges.push_back(make_pair(4,3));
  edges.push_back(make_pair(5,4));
  vector<int> res = s.findMinHeightTrees(6, edges);
  for (int v : res)
    cout << v << " ";
  cout << endl;
  return 0;
}
