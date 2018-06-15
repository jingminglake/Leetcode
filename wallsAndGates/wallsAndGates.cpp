#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.size() == 0 || rooms[0].size() == 0)
            return;
        queue<pair<int, int> > q;
        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[0].size(); j++) {
                if (rooms[i][j] == 0)
                    q.emplace(i, j);
            }
        }
        int dist = 0;
        vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            int size = q.size();
            dist++;
            for (int i = 0; i < size; i++) {
                pair<int, int> p = q.front();
                q.pop();
                for (auto& dir : dirs) {
                    int next_i = p.first + dir.first;
                    int next_j = p.second + dir.second;
                    if (next_i < 0 || next_i >= rooms.size() || next_j < 0 || next_j >= rooms[0].size() || rooms[next_i][next_j] != INT_MAX)
                        continue;
                    rooms[next_i][next_j] = dist;
                    q.emplace(next_i, next_j);
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
