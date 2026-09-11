#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (start == destination) return true;
        vector<vector<bool> > visited(maze.size(), vector<bool>(maze[0].size(), false));
        vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        return dfs(maze, start, destination, visited, dirs);
    }
    bool dfs(vector<vector<int>>& maze, vector<int> start, vector<int>& destination, vector<vector<bool> >& visited, vector<pair<int, int> >& dirs) {
        if (start == destination) return true;
        visited[start[0]][start[1]] = true;
        for (auto& dir : dirs) {
            int next_i = start[0], next_j = start[1];
            while (isValid(maze, next_i, next_j)) {
                next_i += dir.first;
                next_j += dir.second;
            }
            next_i -= dir.first;
            next_j -= dir.second;
            vector<int> next_start = {next_i, next_j};
            if (!visited[next_start[0]][next_start[1]] && dfs(maze, next_start, destination, visited, dirs)) return true;
        }
        return false;
    }
    bool isValid(vector<vector<int>>& maze, int i, int j) {
        return i >= 0 && i < maze.size() && j >= 0 && j < maze[0].size() && maze[i][j] == 0;
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
