#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int res = 0;
        vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1)
                    res += checkNeighbor(grid, i, j, dirs);
            }
        }
        return res;
    }
    int checkNeighbor(vector<vector<int>>& grid, int i, int j, vector<pair<int, int> >& dirs) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (auto& dir : dirs) {
            int next_i = i + dir.first, next_j = j + dir.second;
            if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n || grid[next_i][next_j] == 0)
                res++;
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
