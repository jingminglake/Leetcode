#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
  int countCornerRectangles(vector<vector<int>>& grid) {
    int res = 0;
    if (grid.size() == 0)
      return res;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = i + 1; j < grid.size(); j++) {
	int count = 0;
	for (int k = 0; k < grid[0].size(); k++) {
	  if (grid[i][k] == 1 && grid[j][k] == 1)
	    count++;
	}
	res += count * (count - 1) / 2;
      }
    }
    return res;
  }
};

int main()
{
  Solution s;
  vector<vector<int> > grid = {{1,1,1},
			       {1,1,1},
			       {1,1,1}};
  cout << s.countCornerRectangles(grid);
  cout << endl;
  return 0;
}
