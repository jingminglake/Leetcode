#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
  vector<pair<int, int> > pacificAtlantic(vector<vector<int> >& matrix) {
    vector<pair<int, int> > waterCanFlow;
    int m = matrix.size();
    if (m == 0)
      return waterCanFlow;
    int n = matrix[0].size();
    vector<vector<bool> > pacificCanFlow(m, vector<bool>(n, false));
    vector<vector<bool> > atlanticCanFlow(m, vector<bool>(n, false));
    vector<pair<int, int> > dirs;
    dirs.push_back(make_pair(1, 0));
    dirs.push_back(make_pair(-1, 0));
    dirs.push_back(make_pair(0, 1));
    dirs.push_back(make_pair(0, -1));
    queue<pair<int, int> > q1, q2;
    for (int i = 0; i < m; i++) {
      q1.push(make_pair(i, 0));
      q2.push(make_pair(i, n - 1));
      pacificCanFlow[i][0] = true;
      atlanticCanFlow[i][n-1] = true;
    }//for
    for (int j = 0; j < n; j++) {
      q1.push(make_pair(0, j));
      q2.push(make_pair(m - 1, j));
      pacificCanFlow[0][j] = true;
      atlanticCanFlow[m-1][j] = true;
    }
    bfs(matrix, q1, pacificCanFlow, m, n, dirs);
    bfs(matrix, q2, atlanticCanFlow, m, n, dirs);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
	if (pacificCanFlow[i][j] && atlanticCanFlow[i][j])
	  waterCanFlow.push_back(make_pair(i,j));
      }
    }
    return waterCanFlow;
  }
  void bfs(vector<vector<int> >& matrix, queue<pair<int, int> >& q, vector<vector<bool> >& onceanCanFlow ,int m, int n, vector<pair<int, int> >& dirs) {
    while (!q.empty()) {
      pair<int, int> pos = q.front();
      q.pop();
      for (pair<int, int>& d : dirs) {
	int r = pos.first + d.first;
	int c = pos.second + d.second;
	if (r < 0 || r >= m || c < 0 || c >= n || onceanCanFlow[r][c] || matrix[r][c] < matrix[pos.first][pos.second])
	  continue;
	onceanCanFlow[r][c] = true;
	q.push(make_pair(r,c));
      }
    }//while
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
