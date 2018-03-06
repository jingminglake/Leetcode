#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if (graph.size() == 0)
            return false;
        vector<int> colors(graph.size(), 0);
        for (int i = 0; i < graph.size(); i++) {
            if (colors[i] == 0 && !dfs(graph, colors, 0, i))
                return false;
        }
        return true;
    }
    bool dfs(vector<vector<int> >& graph, vector<int>& colors, int color, int node) {
        if (colors[node] != 0)
            return colors[node] == color;
        colors[node] = color;
        for (int next : graph[node]) {
            int nextColor = (color == 1) ? 2 : 1;
            if (!dfs(graph, colors, nextColor, next))
                return false;
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
