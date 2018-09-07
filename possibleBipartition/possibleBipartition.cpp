#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int> > graph(N + 1);
        for (auto& dislike : dislikes) {
            graph[dislike[0]].push_back(dislike[1]);
            graph[dislike[1]].push_back(dislike[0]);
        }
        vector<int> visited(N + 1, 0); // 0 -> unvisited, 1 -> group one, 2 -> group two
        for (int i = 1; i <= N; i++) {
            if (visited[i] != 0)
                continue;
            if (!dfs(i, 1, graph, visited))
                return false;
        }
        return true;
    }
    bool dfs(int node, int group, vector<vector<int> >& graph, vector<int>& visited) {
        visited[node] = group;
        for (int i : graph[node]) {
            int next_group = group == 1 ? 2 : 1;
            if (visited[i] != 0) {
                if (visited[i] != next_group)
                    return false;
            } else if (!dfs(i, next_group, graph, visited)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    int N = 4;
    vector<vector<int> > dislikes = {{1,2}, {1,3}, {2,4}};
    cout << s.possibleBipartition(N, dislikes) << endl;
    return 0;
}
