#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
    if (maze.size() == 0)
      return false;
    // directions : (0, -1) -> left, (0, 1) -> right, (-1, 0) -> up, (1, 0) ->down
    vector<vector<int>> dp(maze.size(), vector<int>(maze[0].size(), -1));
    return dfs(maze, start[0], start[1], destination, dp);
  }
  bool dfs(vector<vector<int>>& maze, int i, int j, vector<int>& destination, vector<vector<int>>& dp) {
    if (i == destination[0] && j == destination[1]) {
      return true;
    }
    if (dp[i][j] != -1)
      return dp[i][j];
    bool res = false;
    maze[i][j] = -1;
    vector<pair<int, int> > dirs = {make_pair(0, -1), make_pair(0, 1), make_pair(-1, 0), make_pair(1, 0)};
    for (auto& dir : dirs) {
      int m = i;
      int n = j;
      while (m >= 0 && m < maze.size() && n >= 0 && n < maze[0].size() && maze[m][n] != 1) {
	m += dir.first;
	n += dir.second;
      }
      m -= dir.first;
      n -= dir.second;
      if (maze[m][n] == 0)
	res |= dfs(maze, m, n, destination, dp);
    }
    dp[i][j] = res;
    return dp[i][j];
  }
};

int main()
{
  Solution s;
  vector<vector<int> > maze = { {0,0,1,0,0},
				{0,0,0,0,0},
				{0,0,0,1,0},
				{1,1,0,1,1},
				{0,0,0,0,0}};
  vector<int> start = {0, 4};
  vector<int> dest = {3, 2};
  cout << s.hasPath(maze, start, dest) << endl;
  return 0;
}
