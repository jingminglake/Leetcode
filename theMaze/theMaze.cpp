#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<bool> > visited(maze.size(), vector<bool>(maze[0].size(), false));
        vector<pair<int, int> > dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        visited[start[0]][start[1]] = true;
        return dfs(maze, start[0], start[1], destination, visited, dirs);
    }
    bool dfs (vector<vector<int> >& maze, int start_i, int start_j, vector<int>& destination, vector<vector<bool> >& visited, vector<pair<int, int> >& dirs) {
        if (start_i == destination[0] && start_j == destination[1])
            return true;
        for (auto& dir : dirs) {
            int next_i = start_i + dir.first;
            int next_j = start_j + dir.second;
            while (next_i >= 0 && next_i < maze.size() && next_j >= 0 && next_j < maze[0].size() && maze[next_i][next_j] != 1) {
                next_i += dir.first;
                next_j += dir.second;
            }
            next_i -= dir.first;
            next_j -= dir.second;
            if (next_i < 0 || next_i >= maze.size() || next_j < 0 || next_j >= maze[0].size() || maze[next_i][next_j] == 1 || visited[next_i][next_j])
                continue;
            visited[next_i][next_j] = true;
            if (dfs (maze, next_i, next_j, destination, visited, dirs))
                return true;
        }
        return false;
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
