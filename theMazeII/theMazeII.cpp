#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    class Point {
    public:
        Point(int _x, int _y, int _l) : x(_x), y(_y), l(_l) {
            
        }
        int x;
        int y;
        int l;
    };
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        if (m == 0)
            return 0;
        int n = maze[0].size();
        vector<vector<int> > dist(m, vector<int>(n, INT_MAX));
        vector<vector<int> > dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        auto comp = [&](const Point& p1, const Point& p2) {
            return p1.l > p2.l;
        };
        typedef priority_queue<Point, vector<Point>, decltype(comp) > my_pq;
        my_pq pq(comp);
        pq.push(Point(start[0], start[1], 0));
        while (!pq.empty()) {
            Point p = pq.top();
            pq.pop();
            if (dist[p.x][p.y] <= p.l)
                continue;
            dist[p.x][p.y] = p.l;
            for (int i = 0; i < dirs.size(); i++) {
                int xx = p.x, yy = p.y, l = p.l;
                while (xx >= 0 && xx < m && yy >= 0 && yy < n && maze[xx][yy] == 0) {
                    xx += dirs[i][0];
                    yy += dirs[i][1];
                    l++;
                }
                xx -= dirs[i][0];
                yy -= dirs[i][1];
                l--;
                pq.push(Point(xx, yy, l));
            }
        } // while
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
