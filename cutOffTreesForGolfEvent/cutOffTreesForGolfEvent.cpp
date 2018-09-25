#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    class Compare {
    public:
        bool operator()(const tuple<int, int, int>& t1, const tuple<int, int, int>& t2) const {
            return get<0>(t1) < get<0>(t2);
        }
    };
    int cutOffTree(vector<vector<int>>& forest) {
        if (forest.size() == 0 || forest[0].size() == 0)
            return -1;
        int m = forest.size(), n = forest[0].size();
        vector<tuple<int, int, int> > trees;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] != 0) {
                    trees.emplace_back(forest[i][j], i, j);
                }
            }
        }
        if (trees.size() == 0)
            return -1;
        sort(trees.begin(), trees.end(), Compare());
        vector<pair<int, int> > dirs = {{-1,0}, {1,0}, {0,-1}, {0, 1}};
        int res = bfs(forest, 0, 0, get<1>(trees[0]), get<2>(trees[0]), dirs);
        if (res == -1)
            return res;
        for (int i = 1; i < trees.size(); i++) {
            int dist = bfs(forest, get<1>(trees[i-1]), get<2>(trees[i-1]), get<1>(trees[i]), get<2>(trees[i]), dirs);
            if (dist == -1)
                return -1;
            else
                res += dist;
        }
        return res;
    }
    int bfs(vector<vector<int> >& forest, int si, int sj, int di, int dj, vector<pair<int, int> >& dirs) {
        int dist = 0;
        if (si == di && sj == dj)
            return dist;
        int m = forest.size(), n = forest[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        queue<pair<int, int> > q;
        q.emplace(si, sj);
        visited[si][sj] = true;
        
        while (!q.empty()) {
            int size = q.size();
            dist++;
            for (int i = 0; i < size; i++) {
                pair<int, int>& p = q.front();
                q.pop();
                for (pair<int, int>& dir : dirs) {
                    int next_i = p.first + dir.first;
                    int next_j = p.second + dir.second;
                    if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n || forest[next_i][next_j] == 0 || visited[next_i][next_j])
                        continue;
                    if (next_i == di && next_j == dj) {
                        return dist;
                    }
                    q.emplace(next_i, next_j);
                    visited[next_i][next_j] = true;
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
