#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int maxAreaOfIsland(vector<vector<int> >& grid) {
    int res = 0;
    int m = grid.size();
    if (m == 0)
      return res;
    int n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
	if (grid[i][j] == 1) {
	  res = max(res, dfs(grid, i, j));
	}
      }
    }
    return res;
  }
  int dfs(vector<vector<int> >& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
	return 0;
    grid[i][j] = 0;
    return 1 + dfs(grid, i + 1, j) + dfs(grid, i - 1, j) + dfs(grid, i, j + 1) + dfs(grid, i, j - 1);
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
