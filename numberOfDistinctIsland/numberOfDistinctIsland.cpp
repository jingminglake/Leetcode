#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int m = grid.size(), n = grid[0].size();
        unordered_set<string> s;
        vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    string island;
                    bfs(grid, i, j, island, dirs, visited);
                    s.insert(island);
                }
            }
        return s.size();
    }
    void bfs(vector<vector<int>>& grid, int i, int j, string& island, vector<pair<int, int> >& dirs, vector<vector<bool> >& visited) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int> > q;
        visited[i][j] = true;
        q.emplace(i, j);
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for (int d = 0; d < dirs.size(); d++) {
                int next_i = p.first + dirs[d].first;
                int next_j = p.second + dirs[d].second;
                if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n || visited[next_i][next_j] || grid[next_i][next_j] == 0)
                    continue;
                island += to_string(d);
                visited[next_i][next_j] = true;
                q.emplace(next_i, next_j);
            }
            island += ",";
        }
    }
};

int main()
{
    Solution s;
    int a1[5] = {1,1,0,1,1};
    int a2[5] = {1,0,0,0,0};
    int a3[5] = {0,0,0,0,1};
    int a4[5] = {1,1,0,1,1};
    vector<int> vec1(a1, a1+5);
    vector<int> vec2(a2, a2+5);
    vector<int> vec3(a3, a3+5);
    vector<int> vec4(a4, a4+5);
    vector<vector<int> > grid;
    grid.push_back(vec1);
    grid.push_back(vec2);
    grid.push_back(vec3);
    grid.push_back(vec4);
    cout << s.numDistinctIslands(grid) << endl;
    return 0;
}
