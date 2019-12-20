#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    Node(int _val, int _x, int _y) : val(_val), x(_x), y(_y) {};
    bool operator<(const Node& n) const {
        return val < n.val;
    }
    int val;
    int x;
    int y;
};

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        if (forest.size() == 0 || forest[0].size() == 0) return -1;
        int m = forest.size(), n = forest[0].size();
        vector<Node> trees;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] != 0) trees.push_back(Node(forest[i][j], i, j));
            }
        }
        if (trees.size() == 0) return -1;
        sort(trees.begin(), trees.end());
        vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int res = bfs(forest, 0, 0, trees[0].x, trees[0].y, dirs);
        if (res == -1) return res;
        for (int i = 0; i < trees.size() - 1; i++) {
            int dist = bfs(forest, trees[i].x, trees[i].y, trees[i + 1].x, trees[i + 1].y, dirs);
            if (dist == -1) return -1;
            res += dist;
        }
        return res;
    }
    int bfs(vector<vector<int> >& forest, int start_x, int start_y, int dest_x, int dest_y, vector<pair<int, int> >& dirs) {
        int dist = 0;
        if (start_x == dest_x && start_y == dest_y) return dist;
        int m = forest.size(), n = forest[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        queue<Node> q;
        q.push(Node(forest[start_x][start_y], start_x, start_y));
        visited[start_x][start_y] = true;
        while (!q.empty()) {
            dist++;
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                Node node = q.front(); q.pop();
                for (auto& dir : dirs) {
                    int next_x = node.x + dir.first;
                    int next_y = node.y + dir.second;
                    if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n) continue;
                    if (forest[next_x][next_y] == 0 || visited[next_x][next_y]) continue;
                    if (next_x == dest_x && next_y == dest_y) return dist;
                    q.push(Node(forest[next_x][next_y], next_x, next_y));
                    visited[next_x][next_y] = true;
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution sl;
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {0,0,4};
    vector<int> v3 = {7,6,5};
    vector<vector<int> > forest;
    forest.push_back(v1);
    forest.push_back(v2);
    forest.push_back(v3);
    cout << sl.cutOffTree(forest) << endl;
    return 0;
}
