#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
  vector<vector<char> > updateBoard(vector<vector<char> >& board, vector<int>& click) {
    int m = board.size();
    int n = board[0].size();
    queue<vector<int> > q;
    q.push(click);
    while (!q.empty()) {
      vector<int> cell = q.front();
      q.pop();
      int row = cell[0], col = cell[1];
      if (board[row][col] == 'M') {
	board[row][col] = 'X';
      } else { //empty
	int numberOfMine = 0;
	for (int i = -1; i < 2; i++) {
	  for (int j = -1; j < 2; j++) {
	    if (i == 0 && j == 0)
	      continue;
	    int r = row + i, c = col + j;
	    if (r < 0 || r >= m || c < 0 || c >= n)
	      continue;
	    if (board[r][c] == 'M' || board[r][c] == 'X')
	      numberOfMine++;
	  }
	}
	if (numberOfMine > 0) {
	  board[row][col] = numberOfMine + '0';
	} else {
	  board[row][col] = 'B';
	  for (int i = -1; i < 2; i++) {
	    for (int j = -1; j < 2; j++) {
	      if (i == 0 && j == 0)
		continue;
	      int r = row + i, c = col + j;
	      if (r < 0 || r >= m || c < 0 || c >= n)
		continue;
	      if (board[r][c] == 'E') {
		vector<int> clickNext;
                clickNext.push_back(r);
		clickNext.push_back(c);
		q.push(clickNext);
		board[r][c] = 'B';
	      }
	    }
	  }
	}//else
      }
    }//while
    return board;
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
