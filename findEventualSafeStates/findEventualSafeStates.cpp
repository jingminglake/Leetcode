#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        if (graph.size() == 0)
            return res;
        vector<int> visited(graph.size(), 0); // 0 -> unvisited, 1 -> safe, 2->visited
        for (int i = 0; i < graph.size(); i++) {
            if (dfs(graph, i, visited))
                res.push_back(i);
        }
        return res;
    }
    bool dfs(vector<vector<int> >& graph, int startNode, vector<int>& visited) {
        if (visited[startNode] != 0)
            return visited[startNode] == 1;
        visited[startNode] = 2;
        for (int neighbor : graph[startNode]) {
            if (!dfs(graph, neighbor, visited))
                return false;
        }
        visited[startNode] = 1;
        return true;
    }
};

int main() {
  Solution s;
  vector<vector<int> > graph = {{1,2}, {2,3}, {5}, {0}, {5}, {}, {}};
  for (int i : s.eventualSafeNodes(graph))
    cout << i << " ";
  cout << endl;
  return 0;
}
