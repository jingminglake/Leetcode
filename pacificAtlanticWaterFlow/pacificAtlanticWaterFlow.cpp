#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int> > res;
        int m = matrix.size();
        if (m == 0)
            return res;
        int n = matrix[0].size();
        vector<vector<bool> > pacificCanFlow(m, vector<bool>(n, false));
        vector<vector<bool> > atlanticCanFlow(m, vector<bool>(n, false));
        queue<pair<int, int> > q1, q2;
        for (int i = 0; i < m; i++) {
            q1.push({i, 0});
            q2.push({i, n - 1});
            pacificCanFlow[i][0] = true;
            atlanticCanFlow[i][n - 1] = true;
        }
        for (int j = 0; j < n; j++) {
            q1.push({0, j});
            q2.push({m - 1, j});
            pacificCanFlow[0][j] = true;
            atlanticCanFlow[m - 1][j] = true;
        }
        bfs (matrix, q1, pacificCanFlow);
        bfs (matrix, q2, atlanticCanFlow);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacificCanFlow[i][j] && atlanticCanFlow[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }
    void bfs(vector<vector<int>>& matrix, queue<pair<int, int> >& q, vector<vector<bool> >& canFlow) {
        vector<pair<int, int> > dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for (auto& dir : dirs) {
                int r = p.first + dir.first;
                int c = p.second + dir.second;
                if (r < 0 || r >= matrix.size() || c < 0 || c >= matrix[0].size() || canFlow[r][c] || matrix[r][c] < matrix[p.first][p.second])
                    continue;
                canFlow[r][c] = true;
                q.push({r, c});
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
