#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0 || word.length() == 0)
            return false;
        int m = board.size(), n = board[0].size();
        vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    char c = board[i][j];
                    board[i][j] = '#';
                    if (dfs(board, i, j, word, 1, dirs)) {
                        board[i][j] = c;
                        return true;
                    }
                    board[i][j] = c;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char> >& board, int i, int j, string& word, int index, vector<pair<int, int> >& dirs) {
        if (index == word.length())
            return true;
        for (auto& dir : dirs) {
            int next_i = i + dir.first;
            int next_j = j + dir.second;
            if (next_i < 0 || next_i >= board.size() || next_j < 0 || next_j >= board[0].size() || board[next_i][next_j] == '#' || board[next_i][next_j] != word[index])
                continue;
            char t = board[next_i][next_j];
            board[next_i][next_j] = '#';
            if (dfs(board, next_i, next_j, word, index + 1, dirs)) {
                board[next_i][next_j] = t;
                return true;
            }
            board[next_i][next_j] = t;
        }
        return false;
    }
};

int main()
{
    Solution s;
    char a0[4] = {'A', 'B', 'C', 'E'};
    char a1[4] = {'S', 'F', 'C', 'S'};
    char a2[4] = {'A', 'D', 'E', 'E'};
    vector<char> vec0(a0, a0+4);
    vector<char> vec1(a1, a1+4);
    vector<char> vec2(a2, a2+4);  
    vector<vector<char> > vec;
    vec.push_back(vec0);
    vec.push_back(vec1);
    vec.push_back(vec2);
    string word = "ABCCED";
    cout << s.exist(vec, word);
    cout << endl;
    return 0;
}
