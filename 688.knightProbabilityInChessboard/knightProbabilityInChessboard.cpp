class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double> > dp0(N, vector<double>(N, 0.0));
        dp0[r][c] = 1.0;
        vector<pair<int, int> > dirs = {make_pair(1, 2), make_pair(-1, 2), make_pair(1, -2), make_pair(-1, -2), make_pair(2, 1), make_pair(-2, 1), make_pair(2, -1), make_pair(-2, -1)};
        for (int k = 0; k < K; k++) {
            vector<vector<double> > dp1(N, vector<double>(N, 0.0));
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    for (auto& dir : dirs) {
                        int x = i + dir.first;
                        int y = j + dir.second;
                        if (x < 0 || x >= N || y < 0 || y >= N)
                            continue;
                        dp1[x][y] += dp0[i][j];
                    }
                }
            }
            swap(dp0, dp1);
        }
        double total = 0.0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                total += dp0[i][j];
            }
        }
        return total / pow(8, K);
    }
};
