#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)
            return -1;
        int n = grid[0].size();
        int numOfBuildings = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    numOfBuildings++;
            }
        }
        vector<vector<int> > hits(m, vector<int>(n, 0));
        vector<vector<int> > distSum(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    if (!bfs(i, j, grid, hits, distSum, numOfBuildings))
                        return -1;
                }
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && hits[i][j] == numOfBuildings) {
                    res = min (res, distSum[i][j]);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
    bool bfs (int startI, int startJ, vector<vector<int> >& grid, vector<vector<int> >& hits, vector<vector<int> >& distSum, int numOfBuildings) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        visited[startI][startJ] = true;
        int count = 1;
        int dist = 0;
        queue<pair<int, int> > q;
        q.emplace(startI, startJ);
        vector<pair<int, int> > dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            ++dist;
            int levelCount = q.size();
            for (int k = 0; k < levelCount; k++) {
                pair<int, int> p = q.front();
                q.pop();
                for (auto& dir : dirs) {
                    int i = p.first + dir.first;
                    int j = p.second + dir.second;
                    if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j])
                        continue;
                    visited[i][j] = true;
                    if (grid[i][j] == 0) {
                        q.emplace(i, j);
                        hits[i][j]++;
                        distSum[i][j] += dist;
                    } else if (grid[i][j] == 1) {
                        count++;
                    }
                }
            }
        }// while
        return count == numOfBuildings;
    }
};

int main() {
    Solution s;
    vector<vector<int> > grid = {{1,0,2,0,1},{0,0,0,0,0},{0,0,1,0,0}};
    cout << s.shortestDistance(grid) << endl;
    return 0;
}
