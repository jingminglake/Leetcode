#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        vector<int> res(hits.size(), 0);
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i <= m * n; i++)
            parent.push_back(i);
        count = vector<int>(m * n + 1, 0);
        // build union_find set
        for (auto& hit : hits) {
            if (grid[hit[0]][hit[1]] == 1)
                grid[hit[0]][hit[1]] = 2;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    count[i * n + j] = 1;
                    if (i == 0)
                         union_op(i * n + j, m * n);
                    if (i > 0 && grid[i - 1][j] == 1)
                        union_op(i * n + j, (i - 1) * n + j);
                    if (j > 0 && grid[i][j - 1] == 1)
                        union_op(i * n + j, i * n + j - 1);
                }
            }
        }
        // reverse add
        vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int cur_count = count[m * n];
        //cout << "cur_count: " << count[m * n] << endl;
        for (int i = hits.size() - 1; i >= 0; i--) {
            int x = hits[i][0], y = hits[i][1];
            if (grid[x][y] == 2) {
                count[x * n + y] = 1;
                for (auto& d : dirs) {
                    int next_x = x + d.first;
                    int next_y = y + d.second;
                    if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || grid[next_x][next_y] != 1)
                        continue;
                    union_op(x * n + y, next_x * n + next_y);
                }
                grid[x][y] = 1;
                if (x == 0)
                    union_op(x * n + y, m * n);
                //cout << "count[m * n]: " << count[m * n] << endl;
                res[i] = count[m * n] > cur_count ? count[m * n] - cur_count - 1 : 0; // -1 because the one hitted do not count
                cur_count = count[m * n];
            }
        }
        return res;
    }
    int find_op(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find_op(parent[node]);
    }
    void union_op(int node1, int node2) {
        int p1 = find_op(node1);
        int p2 = find_op(node2);
        if (p1 > p2) {
            parent[p2] = p1;
            count[p1] += count[p2];
            //cout << p1 << "===" << count[p1] << endl;
        } else if (p1 < p2) {
            parent[p1] = p2;
            count[p2] += count[p1];
            //cout << p2 << "===" << count[p2] << endl;
        }
    }
    int m;
    int n;
    vector<int> parent;
    vector<int> count;
};

int main() {
    Solution s;
    vector<vector<int> > grid = {{1,0,0,0},{1,1,1,0}};
    vector<vector<int> > hits = {{1, 0}};
    for (int i : s.hitBricks(grid, hits))
        cout << i << " ";
    cout << endl;
    return 0;
}
