 #include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<int> > m(n, vector<int>());
        vector<bool> visited(n, false);
        for (auto edge : edges) {
            m[edge.first].push_back(edge.second);
            m[edge.second].push_back(edge.first);
        }
        if (!dfs(0, -1, m, visited))
            return false;
        for (auto v : visited) {
            if (!v)
                return false;
        }
        return true;
    }
    bool dfs(int node, int preNode, vector<vector<int> >& m, vector<bool>& visited) {
        if (visited[node])
            return false;
        visited[node] = true;
        for (auto neighbor : m[node]) {
            if (neighbor != preNode) {
                if (!dfs(neighbor, node, m, visited))
                    return false;
            }
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
