#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return matrix;
        int m = matrix.size();
        int n = matrix[0].size();
        queue<pair<int, int> > q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    q.emplace(i, j);
                } else {
                    matrix[i][j] = INT_MAX;
                }
            }
        }
        vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int dis = 0;
        while (!q.empty()) {
            int size = q.size();
            dis++;
            for (int i = 0; i < size; i++) {
                pair<int, int> cur = q.front();
                q.pop();
                for (auto& dir : dirs) {
                    int next_i = cur.first + dir.first;
                    int next_j = cur.second + dir.second;
                    if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n || matrix[next_i][next_j] != INT_MAX)
                        continue;
                    matrix[next_i][next_j] = dis;
                    q.emplace(next_i, next_j);
                }
            }
        }
        return matrix;
    }
};

int main()
{
    Solution s;
    int a1[3] = {0,0,0};
    int a2[3] = {0,1,0};
    int a3[3] = {1,1,1};
    vector<int> vec1(a1, a1+3);
    vector<int> vec2(a2, a2+3);
    vector<int> vec3(a3, a3+3);
    vector<vector<int> > matrix;
    matrix.push_back(vec1);
    matrix.push_back(vec2);
    matrix.push_back(vec3);
    s.updateMatrix(matrix);
    for (vector<int>& v : matrix) {
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
