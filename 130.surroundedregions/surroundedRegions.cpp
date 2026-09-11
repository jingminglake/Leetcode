#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0)
            return;
        int m = board.size(), n = board[0].size();
        queue<pair<int, int> > q;
        vector<vector<bool> > not_surround(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                q.emplace(i, 0);
                not_surround[i][0] = true;
            }
            if (board[i][n - 1] == 'O') {
                q.emplace(i, n - 1);
                not_surround[i][n - 1] = true;
            }
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                q.emplace(0, j);
                not_surround[0][j] = true;
            }
            if (board[m - 1][j] == 'O') {
                q.emplace(m - 1, j);
                not_surround[m - 1][j] = true;
            }
        }
        vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for (auto& dir : dirs) {
                int next_i = p.first + dir.first;
                int next_j = p.second + dir.second;
                if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n || not_surround[next_i][next_j] || board[next_i][next_j] == 'X')
                    continue;
                not_surround[next_i][next_j] = true;
                q.emplace(next_i, next_j);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && !not_surround[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};

int main()
{
    Solution s;
    char a1[4] = {'X','X','X','X'};
    char a2[4] = {'X','O','O','X'};
    char a3[4] = {'X','X','O','X'};
    char a4[4] = {'X','O','X','X'};
    vector<char> vec1(a1, a1+4);
    vector<char> vec2(a2, a2+4);
    vector<char> vec3(a3, a3+4);
    vector<char> vec4(a4, a4+4);
    vector<vector<char> > board;
    board.push_back(vec1);
    board.push_back(vec2);
    board.push_back(vec3);
    board.push_back(vec4);
    s.solve(board);
    for (vector<char>& v : board) {
        for (char i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
