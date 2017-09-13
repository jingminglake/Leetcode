// clang++ uniquePathsII.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    int m = obstacleGrid.size();
    if (m == 0)
      return 0;
    int n = obstacleGrid[0].size();
    vector<int> cur(m, 0);
    cur[0] = 1;
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < m; i++) {
	if (obstacleGrid[i][j] != 1 && i >= 1) {
	  cur[i] += cur[i-1];
	} else if (obstacleGrid[i][j] == 1) {
	  cur[i] = 0;
	}
      }
    }//for
    return cur[m - 1];
  }
};

int main()
{
  Solution s;
  vector<vector<int> > grid = {{0,0,0}, {0,1,0}, {0,0,0}};
  cout << s.uniquePathsWithObstacles(grid) << endl;;
  return 0;
}
