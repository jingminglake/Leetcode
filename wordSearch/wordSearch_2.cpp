#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0 || word.length() == 0) return false;
        vector<pair<int, int> > dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, word, 0, i, j, dirs)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int index, int i, int j, vector<pair<int, int> >& dirs) {
        if (index == word.length()) return true;
        if (word[index] != board[i][j]) return false;
        else if (index == word.length() - 1) return true;
        char c = board[i][j];
        board[i][j] = '#';
        for (auto& dir : dirs) {
            int next_i = i + dir.first, next_j = j + dir.second;
            if (next_i < 0 || next_i >= board.size() || next_j < 0 || next_j >= board[0].size()) continue;
            if (board[next_i][next_j] == '#') continue;
            if (dfs(board, word, index + 1, next_i, next_j, dirs)) {
                board[i][j] = c;
                return true;
            }
        }
        board[i][j] = c;
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
