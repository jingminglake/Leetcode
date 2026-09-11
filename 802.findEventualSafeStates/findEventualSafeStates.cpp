#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        if (graph.size() == 0)
            return res;
        vector<int> status(graph.size(), 0); // 0 -> unvisited, 1 -> visited, 2 -> safe, 3 -> unsafe
        for (int i = 0; i < graph.size(); i++) {
            if (dfs(graph, i, status) == 2)
                res.push_back(i);
        }
        return res;
    }
    int dfs(vector<vector<int> >& graph, int startNode, vector<int>& status) {
        if (status[startNode] == 2 || status[startNode] == 3)
            return status[startNode];
        status[startNode] = 1;
        for (int neighbor : graph[startNode]) {
            if (status[neighbor] == 1 || dfs(graph, neighbor, status) == 3)
                return status[startNode] = 3;
        }
        return status[startNode] = 2;
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
