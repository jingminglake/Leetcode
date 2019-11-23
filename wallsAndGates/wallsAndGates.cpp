#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.size() == 0 || rooms[0].size() == 0) return;
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int, int> > q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        int dist = 0;
        vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            dist++;
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                pair<int, int> p = q.front(); q.pop();
                for (auto& dir : dirs) {
                    int next_i = p.first + dir.first;
                    int next_j = p.second + dir.second;
                    if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n) continue;
                    if (rooms[next_i][next_j] == -1 || rooms[next_i][next_j] <= dist) continue;
                    rooms[next_i][next_j] = dist;
                    q.push({next_i, next_j});
                }
            }
        }
    }
};

int main()
{
    Solution s;
    int a1[4] = {INT_MAX,-1,0, INT_MAX};
    int a2[4] = {INT_MAX,INT_MAX,INT_MAX,-1};
    int a3[4] = {INT_MAX,-1,INT_MAX,-1};
    int a4[4] = {0,-1,INT_MAX,INT_MAX};
    vector<int> vec1(a1, a1+4);
    vector<int> vec2(a2, a2+4);
    vector<int> vec3(a3, a3+4);
    vector<int> vec4(a4, a4+4);
    vector<vector<int> > matrix;
    matrix.push_back(vec1);
    matrix.push_back(vec2);
    matrix.push_back(vec3);
    matrix.push_back(vec4);
    s.wallsAndGates(matrix);
    for (vector<int>& v : matrix) {
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
