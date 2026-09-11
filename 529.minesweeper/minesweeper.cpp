#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size(), n = board[0].size();
        char c = board[click[0]][click[1]];
        if (c == 'B' || isdigit(c))
            return board;
        else if (c == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        queue<vector<int> > q;
        q.push(click);
        vector<pair<int, int> > dirs = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1, 0}, {1,1}};
        while (!q.empty()) {
            vector<int> p = q.front();
            q.pop();
            c = board[p[0]][p[1]];
            if (c == 'B' || isdigit(c))
                continue;
            int num = numOfMine(board, p[0], p[1], dirs);
            if (num != 0) {
                board[p[0]][p[1]] = num + '0';
                continue;
            }
            board[p[0]][p[1]] = 'B';
            for (auto& dir : dirs) {
                int next_i = p[0] + dir.first;
                int next_j = p[1] + dir.second;
                if (next_i < 0 || next_i >= m || next_j < 0 || next_j >= n || board[next_i][next_j] != 'E')
                    continue;
                q.push({next_i, next_j});
            }
        }
        return board;
    }
    int numOfMine(vector<vector<char> >& board, int i, int j, vector<pair<int, int> >& dirs) {
        int res = 0;
        int m = board.size(), n = board[0].size();
        for (auto& dir : dirs) {
            int neighbor_i = i + dir.first;
            int neighbor_j = j + dir.second;
            if (neighbor_i < 0 || neighbor_i >= m || neighbor_j < 0 || neighbor_j >= n || board[neighbor_i][neighbor_j] != 'M')
                continue;
            res++;
        }
        return res;
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
