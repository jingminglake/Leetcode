#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> visited(N, 0); // 0 -> unvisited, 1 -> group one, 2 -> group two
        for (int i = 0; i < N; i++) {
            if (visited[i] != 0)
                continue;
            if (!dfs(i, 1, graph, visited))
                return false;
        }
        return true;
    }
    bool dfs(int node, int group, vector<vector<int> >& graph, vector<int>& visited) {
        visited[node] = group;
        for (int neighbor : graph[node]) {
            int next_group = group == 1 ? 2 : 1;
            if (visited[neighbor]) {
                if (visited[neighbor] != next_group)
                    return false;
            } else if (!dfs(neighbor, next_group, graph, visited)) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > matrix = {{1,3}, {0,2}, {1,3}, {0,2}};
    cout << s.isBipartite(matrix) << endl;
    return 0;
}
