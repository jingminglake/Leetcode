#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0 || matrix[0].size() == 0) return res;
        int m = matrix.size(), n = matrix[0].size();
        vector<pair<int, int> > dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>> visited (m, vector<bool>(n, false));
        queue<pair<int, int> > q;
        q.push({0, 0});
        visited[0][0] = true;
        int d = 0;
        while (!q.empty()) {
            pair<int, int> p = q.front(); q.pop();
            res.push_back(matrix[p.first][p.second]);
            int next_i = p.first + dirs[d].first;
            int next_j = p.second + dirs[d].second;
            if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n || visited[next_i][next_j]) {
                d = (d + 1) % 4;
                next_i = p.first + dirs[d].first;
                next_j = p.second + dirs[d].second;
                
            }
            if (next_i >= 0 && next_i < m && next_j >= 0 && next_j < n && !visited[next_i][next_j]) {
                q.push({next_i, next_j});
                visited[next_i][next_j] = true;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> row1 = {5,1,9,11};
    vector<int> row2 = {2,4,8,10};
    vector<int> row3 = {13,3,6,7};
    vector<int> row4 = {15,14,12,16};
    vector<vector<int> > matrix;
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    matrix.push_back(row4);
    vector<int> res = s.spiralOrder(matrix);
    for (int i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
