#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (start == destination)
            return true;
        vector<vector<bool> > visited(maze.size(), vector<bool>(maze[0].size(), false));
        vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        visited[start[0]][start[1]] = true;
        return dfs(maze, start[0], start[1], destination, dirs, visited);
    }
    bool dfs(vector<vector<int> >& maze, int i, int j, vector<int>& destination, vector<pair<int, int> >& dirs, vector<vector<bool> >& visited) {
        if (i == destination[0] && j == destination[1])
            return true;
        for (auto& dir : dirs) {
            int next_i = i + dir.first;
            int next_j = j + dir.second;
            while (isValid(maze, next_i, next_j)) {
                next_i += dir.first;
                next_j += dir.second;
            }
            next_i -= dir.first;
            next_j -= dir.second;
            if (!isValid(maze, next_i, next_j) || visited[next_i][next_j])
                continue;
            visited[next_i][next_j] = true;
            if (dfs(maze, next_i, next_j, destination, dirs, visited)) {
                return true;
            }
        }
        return false;
    }
    bool isValid(vector<vector<int> >& maze, int i, int j) {
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
