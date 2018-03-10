#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int> >& grid) {
        int res = 0;
        if (grid.size() == 0)
            return res;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0)
                    continue;
                if (i - 1 < 0 || grid[i - 1][j] == 0)
                    res++;
                if (j - 1 < 0 || grid[i][j - 1] == 0)
                    res++;
                if (j + 1 >= grid[0].size() || grid[i][j + 1] == 0)
                    res++;
                if (i + 1 >= grid.size() || grid[i + 1][j] == 0)
                    res++;
            }
        }
        return res;
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
  cout << s.islandPerimeter(grid);
  cout << endl;
  return 0;
}
