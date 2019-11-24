#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        vector<pair<int, int> > dirs = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
        queue<pair<int, int> > q;
        int num = numOfMines(click[0], click[1], board, dirs);
        if (num == 0) {
             board[click[0]][click[1]] = 'B';
            q.push({click[0], click[1]});
        } else {
            board[click[0]][click[1]] = '0' + num;
        }
        while (!q.empty()) {
            pair<int, int> p = q.front(); q.pop();
            for (auto& dir : dirs) {
                int next_i = p.first + dir.first;
                int next_j = p.second + dir.second;
                if (!valid(next_i, next_j, board)) continue;
                if (board[next_i][next_j] == 'E') {
                    int num = numOfMines(next_i, next_j, board, dirs);
                    if (num == 0) { 
                        board[next_i][next_j] = 'B';
                        q.push({next_i, next_j});
                    } else {
                        board[next_i][next_j] = '0' + num;
                    }
                }
            }
        }
        return board;
    }
    int numOfMines(int i, int j, vector<vector<char>>& board, vector<pair<int, int> >& dirs) {
        int num = 0;
        for (auto& dir : dirs) {
            int neighbor_i = i + dir.first;
            int neighbor_j = j + dir.second;
            if (!valid(neighbor_i, neighbor_j, board)) continue;
            if (board[neighbor_i][neighbor_j] == 'M') num++;
        }
        return num;
    }
    bool valid(int i, int j, vector<vector<char>>& board) {
        return i >= 0 && i < board.size() && j >= 0 && j < board[0].size();
    }
};

int main()
{
    Solution s;
    char c1[5] = {'B', '1', 'E', '1', 'B'};
    char c2[5] = {'B', '1', 'M', '1', 'B'};
    char c3[5] = {'B', '1', '1', '1', 'B'};
    char c4[5] = {'B', 'B', 'B', 'B', 'B'};
    vector<char> vec1(c1, c1+5);
    vector<char> vec2(c2, c2+5);
    vector<char> vec3(c3, c3+5);
    vector<char> vec4(c4, c4+5);
    vector<vector<char> > board;
    board.push_back(vec1);
    board.push_back(vec2);
    board.push_back(vec3);
    board.push_back(vec4);
    int a[2] = {1,2};
    vector<int> click(a, a+2);
    vector<vector<char> > res = s.updateBoard(board, click);
    for (vector<char>& v : res) {
        for (char & c : v)
            cout << c << " ";
        cout << endl;
    }
    return 0;
}
