#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if (grid.size() == 0)
            return 0;
        set<string> s;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    string island;
                    bfs(grid, i, j, island);
                    s.insert(island);
                }
            }
        return s.size();
    }
    void bfs(vector<vector<int>>& grid, int i, int j, string& island) {
        queue<pair<int, int> > q;
        grid[i][j] = 0;
        q.push(make_pair(i, j));
        vector<pair<int, int> > dirs = {make_pair(0, -1), make_pair(0, 1), make_pair(-1, 0), make_pair(1, 0)};
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for (int d = 0; d < dirs.size(); d++) {
                int m = p.first + dirs[d].first;
                int n = p.second + dirs[d].second;
                if (m < 0 || m >= grid.size() || n < 0 || n >= grid[0].size() || grid[m][n] == 0)
                    continue;
                island += to_string(d);
                grid[m][n] = 0;
                q.push(make_pair(m, n));
            }
            island += ",";
        }
    }
};

int main()
{
  Solution s;
  int a1[5] = {1,1,0,1,1};
  int a2[5] = {1,0,0,0,0};
  int a3[5] = {0,0,0,0,1};
  int a4[5] = {1,1,0,1,1};
  vector<int> vec1(a1, a1+5);
  vector<int> vec2(a2, a2+5);
  vector<int> vec3(a3, a3+5);
  vector<int> vec4(a4, a4+5);
  vector<vector<int> > grid;
  grid.push_back(vec1);
  grid.push_back(vec2);
  grid.push_back(vec3);
  grid.push_back(vec4);
  cout << s.numDistinctIslands(grid) << endl;
  return 0;
}
