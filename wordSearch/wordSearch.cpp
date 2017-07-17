#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Solution{
public:
  bool exist(vector<vector<char> >& board, string word) {
    for (int y = 0; y < board.size(); y++) {
      for (int x = 0; x < board[y].size(); x++) {
	if (findFromHere(board, x, y, word, 0))
	  return true;
      }
    }
    return false;
  }
  bool findFromHere(vector<vector<char> >& board, int x, int y, string word, int depth) {
    if (depth == word.length())
      return true;
    if (y < 0 || x < 0 || y == board.size() || x == board[y].size())
      return false;
    if (board[y][x] != word[depth])
      return false;
    board[y][x] = '*'; 
    bool find = findFromHere(board, x+1, y, word, depth+1)
	    || findFromHere(board, x-1, y, word, depth+1)
	    || findFromHere(board, x, y+1, word, depth+1)
	    || findFromHere(board, x, y-1, word, depth+1);
    board[y][x] = word[depth];
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
