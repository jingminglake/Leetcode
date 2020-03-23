class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0;
        vector<vector<int>> matrix = grid;
        int m = matrix.size(), n = matrix[0].size();
        queue<vector<int>> q;
        int numOfOne = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 2) q.push({i, j});
                if (matrix[i][j] == 1) numOfOne++;
            }
        }
        if (numOfOne == 0) return 0;
        vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        while (!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                vector<int> pos = q.front(); q.pop();
                for (vector<int>& dir : dirs) {
                    int next_i = pos[0] + dir[0];
                    int next_j = pos[1] + dir[1];
                    if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n || matrix[next_i][next_j] != 1)
                        continue;
                    matrix[next_i][next_j] = 2;
                    numOfOne--;
                    q.push({next_i, next_j});
                }
            }
            res++;
        }
        if (numOfOne == 0) return res - 1;
        else return -1;
    }
};
