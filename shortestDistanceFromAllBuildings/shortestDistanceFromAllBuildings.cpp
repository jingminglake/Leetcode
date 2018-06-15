#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int res = INT_MAX;
        if (grid.size() == 0 || grid[0].size() == 0)
            return -1;
        int m = grid.size(), n = grid[0].size();
        int total_building_num = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    total_building_num++;
            }
        }
        if (!total_building_num)
            return res;
        vector<vector<int> > dist_sum(m, vector<int>(n, 0));
        vector<vector<int> > building_num(m, vector<int>(n, 0));
        // bfs
        vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    if (!bfs (i, j, grid, dist_sum, building_num, dirs, visited, total_building_num) )
                        return -1;
            }
        }
        
        // get shorest distance
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (building_num[i][j] == total_building_num && dist_sum[i][j] != 0) {
                    res = min (res, dist_sum[i][j]);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
    bool bfs (int i, int j, vector<vector<int>>& grid, vector<vector<int> >& dist_sum, vector<vector<int> >& building_num, vector<pair<int, int> >& dirs, vector<vector<bool> > visited, int& total_building_num) {
        int m = grid.size(), n = grid[0].size();
        int count = 1;
        queue<pair<int, int> > q;
        q.emplace(i, j);
        visited[i][j] = true;
        int dist = 0;
        while (!q.empty()) {
            int size = q.size();
            dist++;
            for (int i = 0; i < size; i++) {
                pair<int, int> p = q.front();
                q.pop();
                for (auto& dir : dirs) {
                    int next_i = p.first + dir.first;
                    int next_j = p.second + dir.second;
                    if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n || visited[next_i][next_j])
                        continue;
                    visited[next_i][next_j] = true;
                    if (grid[next_i][next_j] == 0) {
                        dist_sum[next_i][next_j] += dist;
                        building_num[next_i][next_j]++;
                        q.emplace(next_i, next_j);
                    } else if (grid[next_i][next_j] == 1) {
                        count++;
                    }
                }
            }
        }//while
        return count == total_building_num;
    }
};

int main() {
    Solution s;
    vector<vector<int> > grid = {{1,0,2,0,1},{0,0,0,0,0},{0,0,1,0,0}};
    cout << s.shortestDistance(grid) << endl;
    return 0;
}
