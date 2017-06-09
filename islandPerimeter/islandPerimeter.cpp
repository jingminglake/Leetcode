#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int singleNumber(vector<vector<int> >& grid) {
    int ans = 0;
    int rowSize = grid.size();
    if (rowSize == 0)
      return ans;
    int columnSize = grid[0].size();
    for (int i = 0; i < rowSize; i++) {
      for(int j = 0; j < columnSize; j++) {
	if (grid[i][j] == 0)
	  continue;
	if (i == 0)
	  ans++;
	else if (grid[i-1][j] == 0)
	  ans++;
	if (j == 0)
	  ans++;
	else if (grid[i][j-1] == 0)
	  ans++;
	if (i == rowSize - 1)
	  ans++;
	else if (grid[i+1][j] == 0)
	  ans++;
	if (j == columnSize - 1)
	  ans++;
	else if (grid[i][j+1] == 0)
	  ans++;
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int a[4] = {0,1,0,0};
  int b[4] = {1,1,1,0};
  int c[4] = {0,1,0,0};
  int d[4] = {1,1,0,0};
  vector<int> vec1(a, a+4);
  vector<int> vec2(b, b+4);
  vector<int> vec3(c, c+4);
  vector<int> vec4(d, d+4);
  vector<vector<int> > grid;
  grid.push_back(vec1);
  grid.push_back(vec2);
  grid.push_back(vec3);
  grid.push_back(vec4);
  cout << s.singleNumber(grid);
  cout << endl;
  return 0;
}
