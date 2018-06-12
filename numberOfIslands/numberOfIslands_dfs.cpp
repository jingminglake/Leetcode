#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        if (grid.size() == 0)
            return res;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char> >& grid, int start_i, int start_j) {
        if (start_i < 0 || start_i >= grid.size() || start_j < 0 || start_j >= grid[0].size() || grid[start_i][start_j] == '0') {
            return;
        }
        grid[start_i][start_j] = '0';
        dfs (grid, start_i - 1, start_j);
        dfs (grid, start_i + 1, start_j);
        dfs (grid, start_i, start_j - 1);
        dfs (grid, start_i, start_j + 1);
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
