// clang++ gameOfLife.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size() == 0 || board[0].size() == 0)
            return;
        int m = board.size(), n = board[0].size();
        vector<pair<int, int> > dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live_num = 0;
                for (auto& dir : dirs) {
                    int x = dir.first + i;
                    int y = dir.second + j;
                    if (x < 0 || x >= m || y < 0 || y >= n || (board[x][y] & 1) == 0)
                        continue;
                    live_num++;
                }
                if ((board[i][j] & 1) == 1) {
                    if (live_num < 2 || live_num > 3)
                        board[i][j] = 1;
                    else
                        board[i][j] = 3;
                } else {
                    if (live_num == 3)
                        board[i][j] = 2;
                    else
                        board[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = board[i][j] >> 1;
            }
        }
    }
};

int main()
{
    Solution s;
    int a1[4] = {0,0,0,0};
    int a2[4] = {0,1,0,1};
    int a3[4] = {1,0,1,0};
    int a4[4] = {0,0,0,1};
    vector<int> vec1(a1, a1+4);
    vector<int> vec2(a2, a2+4);
    vector<int> vec3(a3, a3+4);
    vector<int> vec4(a4, a4+4);
    vector<vector<int> > matrix;
    matrix.push_back(vec1);
    matrix.push_back(vec2);
    matrix.push_back(vec3);
    matrix.push_back(vec4);
    s.gameOfLife(matrix);
    for (vector<int>& v : matrix) {
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
