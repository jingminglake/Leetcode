#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
  int numIslands(vector<vector<char> >& grid) {
    int numberOfIsland = 0;
    int m = grid.size();
    if (m == 0)
      return numberOfIsland;
    int n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
	if (grid[i][j] == '1') {
	  vector<int> pos;
	  pos.push_back(i);
	  pos.push_back(j);
	  bfs(grid, pos, m, n);
	  numberOfIsland++; 
	}
      }
    }//for
    return numberOfIsland;
  }
  void bfs(vector<vector<char> >& grid, vector<int>& pos, int m, int n) {
    queue<vector<int> > q;
    q.push(pos);
    grid[pos[0]][pos[1]] = '0';
    vector<pair<int, int> > dirs;
    dirs.push_back(make_pair(-1, 0));
    dirs.push_back(make_pair(0, -1));
    dirs.push_back(make_pair(0, 1));
    dirs.push_back(make_pair(1, 0));
    while (!q.empty()) {
      vector<int> pos = q.front();
      q.pop();
      for (pair<int, int>& d : dirs) {
	int r = pos[0] + d.first;
	int c = pos[1] + d.second;
	if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '0')
	  continue;
	if (grid[r][c] == '1') {
	  vector<int> temp;
	  temp.push_back(r);
	  temp.push_back(c);
	  q.push(temp);
	  grid[r][c] = '0';
	}
      }
    }//while
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
