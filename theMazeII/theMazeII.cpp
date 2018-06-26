#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    class Point {
    public:
        int x, y, d;
        Point(int _x, int _y, int _d) : x(_x), y(_y), d(_d) {}
    };
    class Compare {
    public:
        bool operator()(const Point& p1, const Point& p2) const {
            return p1.d > p2.d;
        }
    };
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        if (m == 0)
            return -1;
        int n = maze[0].size();
        if (n == 0)
            return -1;
        priority_queue<Point, vector<Point>, Compare> pq;
        pq.emplace(start[0], start[1], 0);
        vector<vector<int> > dist(m, vector<int>(n, INT_MAX));
        vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!pq.empty()) {
            Point p = pq.top();
            pq.pop();
            if (dist[p.x][p.y] <= p.d)
                continue;
            dist[p.x][p.y] = p.d;
            for (auto& dir : dirs) {
                int next_i = p.x;
                int next_j = p.y;
                int next_dist = p.d;
                while (next_i >= 0 && next_i < m && next_j >= 0 && next_j < n && maze[next_i][next_j] == 0) {
                    next_i += dir.first;
                    next_j += dir.second;
                    next_dist++;
                }
                next_i -= dir.first;
                next_j -= dir.second;
                next_dist--;
                pq.emplace(next_i, next_j, next_dist);
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
