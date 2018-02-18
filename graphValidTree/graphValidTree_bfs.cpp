#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  bool validTree(int n, vector<pair<int, int>>& edges) {
    vector<vector<int> > m(n, vector<int>());
    vector<int> visited(n, 0); // 0 -> unvisited, 1 -> visiting, 2 -> visited
    for (auto edge : edges) {
      m[edge.first].push_back(edge.second);
      m[edge.second].push_back(edge.first);
    }
    if (!bfs(0, m, visited))
      return false;
    for (auto v : visited) {
      if (v == 0)
	return false;
    }
    return true;
  }
  bool bfs(int node, vector<vector<int> >& m, vector<int>& visited) {
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (int neighbor : m[cur]) {
	if (visited[neighbor] == 1)
	  return false;
	if (visited[neighbor] == 2)
	  continue;
	q.push(neighbor);
	visited[neighbor] = 1;
      }
      visited[cur] = 2;
    }
    return true;
  }
};

int main()
{
  Solution s;
  vector<pair<int, int> > edges = {{0,1},
				   {0,2},
				   {0,3},
				   {1,4}};
  cout <<  s.validTree(5, edges) << endl;
  return 0;
}
