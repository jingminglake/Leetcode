#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> colors(N, 0); // 0 -> unvisited, -1 -> group A, 1 -> group B
        for (int i = 0; i < N; i++) {
            if (colors[i] == 0 && !dfs(i, 1, graph, colors))
                return false;
        }
        return true;
    }
    
    bool dfs(int node, int color, vector<vector<int> >& graph, vector<int>& colors) {
        colors[node] = color;
        for (int neighbor : graph[node]) {
            if (colors[neighbor] == 0 && !dfs(neighbor, -color, graph, colors)) {
                return false;
            } else if (colors[neighbor] == color) {
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
