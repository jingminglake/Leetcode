#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
  bool isValidSudoku(vector<vector<char> >& board) {
    bool rowMap[9][9] = {false};
    bool columnMap[9][9] = {false};
    bool subBoxMap[9][9] = {false};
    for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++)
	if (board[i][j] != '.') {
	  int num = board[i][j] - '0' - 1;
	  int k = i / 3 * 3 + j / 3;
	  if (rowMap[i][num] || columnMap[j][num] || subBoxMap[k][num])
	    return false;
	  rowMap[i][num] = columnMap[j][num] = subBoxMap[k][num] = true;
	}
    return true;
  }

};

int main()
{
  vector<vector<char> > board(9, vector<char>(9));
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      board[i][j] = '0' + j + 1;
  Solution s;
  cout << s.isValidSudoku(board) << endl;
  return 0;
}
