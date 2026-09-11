#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<int> > m(n, vector<int>());
        vector<bool> visited(n, false);
        for (auto& edge : edges) {
            m[edge.first].push_back(edge.second);
            m[edge.second].push_back(edge.first);
        }
        // check cycle
        visited[0] = true;
        if (dfs(0, -1, m, visited))
            return false;
        for (bool v : visited) {
            if (!v)
                return false;
        }
        return true;
    }
    bool dfs(int node, int parent, vector<vector<int> >& m, vector<bool>& visited) {
        for (int neighbor : m[node]) {
            if (neighbor == parent)
                continue;
            if (visited[neighbor])
                return true;
            visited[neighbor] = true;
            if (dfs(neighbor, node, m, visited))
                return true;
        }
        return false;
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
