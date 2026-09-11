#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int> > res;
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return res;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool> > pacific_can_flow(m, vector<bool>(n, false));
        vector<vector<bool> > atlantic_can_flow(m, vector<bool>(n, false));
        queue<pair<int, int> > q_pacific, q_atlantic;
        for (int i = 0; i < m; i++) {
            q_pacific.emplace(i, 0);
            q_atlantic.emplace(i, n - 1);
        }
        for (int i = 0; i < n; i++) {
            q_pacific.emplace(0, i);
            q_atlantic.emplace(m - 1, i);
        }
        vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        bfs(q_pacific, dirs, pacific_can_flow, matrix);
        bfs(q_atlantic, dirs, atlantic_can_flow, matrix);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific_can_flow[i][j] && atlantic_can_flow[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }
    void bfs(queue<pair<int, int> >& q, vector<pair<int, int> >& dirs, vector<vector<bool> >& can_flow, vector<vector<int>>& matrix) {
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            can_flow[p.first][p.second] = true;
            for (auto& dir : dirs) {
                int next_i = p.first + dir.first;
                int next_j = p.second + dir.second;
                if (next_i < 0 || next_i >= matrix.size() || next_j < 0 || next_j >= matrix[0].size() || matrix[next_i][next_j] < matrix[p.first][p.second] || can_flow[next_i][next_j])
                    continue;
                q.emplace(next_i, next_j);
            }
        }
    }
};

int main()
{
    Solution s;
    int a1[5] = {1, 2, 2, 3, 5};
    int a2[5] = {3, 2, 3, 4, 4};
    int a3[5] = {2, 4, 5, 3, 1};
    int a4[5] = {6, 7, 1, 4, 5};
    int a5[5] = {5, 1, 1, 2, 4};
    vector<int> vec1(a1, a1+5);
    vector<int> vec2(a2, a2+5);
    vector<int> vec3(a3, a3+5);
    vector<int> vec4(a4, a4+5);
    vector<int> vec5(a5, a5+5);
    vector<vector<int> > matrix;
    matrix.push_back(vec1);
    matrix.push_back(vec2);
    matrix.push_back(vec3);
    matrix.push_back(vec4);
    matrix.push_back(vec5);
    vector<pair<int,int> > res = s.pacificAtlantic(matrix);
    for (pair<int,int>& p : res)
        cout << "(" << p.first << "," << p.second << ")";
    cout << endl;
    return 0;
}
