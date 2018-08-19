#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    class Compare {
    public:
        bool operator()(const tuple<int, int, int>& t1, const tuple<int, int, int>& t2) const {
            return get<2>(t1) > get<2>(t2);
        }
    };
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (maze.size() == 0 || maze[0].size() == 0 || start == destination)
            return 0;
        int m = maze.size(), n = maze[0].size();
        vector<vector<int> > dist(m, vector<int>(n, INT_MAX));
        dist[start[0]][start[1]] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, Compare> pq;
        pq.emplace(start[0], start[1], 0);
        vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!pq.empty()) {
            tuple<int, int, int> t = pq.top();
            pq.pop();
            int i = get<0>(t), j = get<1>(t);
            for (auto& dir : dirs) {
                int next_i = i;
                int next_j = j;
                int d = 0;
                while (next_i >= 0 && next_i < maze.size() && next_j >= 0 && next_j < maze[0].size() && maze[next_i][next_j] == 0) {
                    next_i += dir.first;
                    next_j += dir.second;
                    d++;
                }
                next_i -= dir.first;
                next_j -= dir.second;
                d--;
                if (dist[next_i][next_j] > dist[i][j] + d) {
                    dist[next_i][next_j] = dist[i][j] + d;
                    pq.emplace(next_i, next_j, dist[next_i][next_j]);
                }
            }
        }
        return dist[destination[0]][destination[1]] == INT_MAX ? -1 : dist[destination[0]][destination[1]];
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
  cout << s.shortestDistance(maze, start, dest) << endl;
  return 0;
}
