#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return res;
        vector<vector<bool> > visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        vector<pair<int, int> > dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int index = 0;
        dfs(matrix, visited, dirs, 0, res, 0, 0);
        return res;
    }
    void dfs(vector<vector<int> >& matrix, vector<vector<bool> >& visited, vector<pair<int, int> >& dirs, int index, vector<int>& res, int i, int j) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || visited[i][j])
            return;
        visited[i][j] = true;
        res.push_back(matrix[i][j]);
        int next_i = i + dirs[index % 4].first, next_j = j + dirs[index % 4].second;
        while (next_i >= 0 && next_i < matrix.size() && next_j >= 0 && next_j < matrix[0].size() && !visited[next_i][next_j]) {
            visited[next_i][next_j] = true;
            res.push_back(matrix[next_i][next_j]);
            next_i += dirs[index].first;
            next_j += dirs[index].second;
        }
        next_i -= dirs[index].first;
        next_j -= dirs[index].second;
        next_i += dirs[(index + 1) % 4].first;
        next_j += dirs[(index + 1) % 4].second;
        dfs(matrix, visited, dirs, (index + 1) % 4, res, next_i, next_j);
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
