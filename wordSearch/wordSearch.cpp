#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    bool exist(vector<vector<char> >& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (findFromHere(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
    bool findFromHere(vector<vector<char> >& board, int i, int j, string word, int depth) {
        if (depth == word.length())
            return true;
        if (i < 0 || j < 0 || i == board.size() || j == board[0].size())
            return false;
        if (board[i][j] != word[depth])
            return false;
        board[i][j] = '*'; 
        bool find = findFromHere(board, i + 1, j, word, depth + 1)
                || findFromHere(board, i - 1, j, word, depth + 1)
                || findFromHere(board, i, j + 1, word, depth + 1)
                || findFromHere(board, i, j - 1, word, depth + 1);
        board[i][j] = word[depth];
        return find;
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
