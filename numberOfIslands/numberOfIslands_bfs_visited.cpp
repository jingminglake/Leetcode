#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        if (grid.size() == 0 || grid[0].size() == 0)
            return res;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    bfs(grid, i, j, visited, dirs);
                    res++;
                }
            }
        }
        return res;
    }
    void bfs (vector<vector<char> >& grid, int i, int j, vector<vector<bool> >& visited, vector<pair<int, int> >& dirs) {
        queue<pair<int, int> > q;
        q.emplace(i, j);
        visited[i][j] = true;
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for (auto& dir : dirs) {
                int next_i = dir.first + p.first;
                int next_j = dir.second + p.second;
                if (next_i < 0 || next_i >= grid.size() || next_j < 0 || next_j >= grid[0].size() || grid[next_i][next_j] == '0' || visited[next_i][next_j])
                    continue;
                q.emplace(next_i, next_j);
                visited[next_i][next_j] = true;
            }
        }
    }
};

int main()
{
    Solution s;
    char a1[5] = {'1','1','0','0','0'};
    char a2[5] = {'1','1','0','0','0'};
    char a3[5] = {'0','0','1','0','0'};
    char a4[5] = {'0','0','0','1','1'};
    vector<char> vec1(a1, a1+5);
    vector<char> vec2(a2, a2+5);
    vector<char> vec3(a3, a3+5);
    vector<char> vec4(a4, a4+5);
    vector<vector<char> > grid;
    grid.push_back(vec1);
    grid.push_back(vec2);
    grid.push_back(vec3);
    grid.push_back(vec4);
    cout << s.numIslands(grid) << endl;
    return 0;
}
