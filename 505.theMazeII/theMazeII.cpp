#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    class Node {
    public:
        Node(int _i, int _j, int _d) : i(_i), j(_j), d(_d) {};
        int i;
        int j;
        int d;
    };
    class Compare {
    public:
        bool operator()(const Node& n1, const Node& n2) const {
            return n1.d > n2.d;
        }
    };
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (maze.size() == 0 || maze[0].size() == 0) return -1;
        int m = maze.size(), n = maze[0].size();
        vector<vector<int> > dist(m, vector<int>(n, INT_MAX));
        dist[start[0]][start[1]] = 0;
        priority_queue<Node, vector<Node>, Compare> pq;
        pq.push(Node(start[0], start[1], 0));
        vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!pq.empty()) {
            Node n = pq.top(); pq.pop();
            for (auto& dir : dirs) {
                int next_i = n.i;
                int next_j = n.j;
                int d = 0;
                while (next_i >= 0 && next_i < maze.size() && next_j >= 0 && next_j < maze[0].size() && 
                       maze[next_i][next_j] == 0) {
                    next_i += dir.first;
                    next_j += dir.second;
                    d++;
                }
                next_i -= dir.first;
                next_j -= dir.second;
                d--;
                if (dist[next_i][next_j] > dist[n.i][n.j] + d) {
                    dist[next_i][next_j] = dist[n.i][n.j] + d;
                    pq.push(Node(next_i, next_j, dist[next_i][next_j]));
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
