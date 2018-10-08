#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        if (grid.size() == 0 || grid[0].size() == 0)
            return res;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    res = max (res, bfs(grid, i, j, visited, dirs));
                }
            }
        }
        return res;
    }
    int bfs(vector<vector<int> >& grid, int i, int j, vector<vector<bool> >& visited, vector<pair<int, int> >& dirs) {
        int res = 0;
        queue<pair<int, int> > q;
        q.emplace(i, j);
        visited[i][j] = true;
        res++;
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for (auto& dir : dirs) {
                int next_i = p.first + dir.first;
                int next_j = p.second + dir.second;
                if (next_i < 0 || next_i >= grid.size() || next_j < 0 || next_j >= grid[0].size() || visited[next_i][next_j] || grid[next_i][next_j] == 0)
                    continue;
                q.emplace(next_i, next_j);
                visited[next_i][next_j] = true;
                res++;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > grid;
    vector<int> row1 = {0,0,1,0,0,0,0,1,0,0,0,0,0};
    vector<int> row2 = {0,0,0,0,0,0,0,1,1,1,0,0,0};
    vector<int> row3 = {0,1,1,0,1,0,0,0,0,0,0,0,0};
    vector<int> row4 = {0,1,0,0,1,1,0,0,1,0,1,0,0};
    vector<int> row5 = {0,1,0,0,1,1,0,0,1,1,1,0,0};
    vector<int> row6 = {0,0,0,0,0,0,0,0,0,0,1,0,0};
    vector<int> row7 = {0,0,0,0,0,0,0,1,1,1,0,0,0};
    vector<int> row8 = {0,0,0,0,0,0,0,1,1,0,0,0,0};
    grid.push_back(row1);
    grid.push_back(row2);
    grid.push_back(row3);
    grid.push_back(row4);
    grid.push_back(row5);
    grid.push_back(row6);
    grid.push_back(row7);
    grid.push_back(row8);
    cout << s.maxAreaOfIsland(grid) << endl;
    return 0;
}
