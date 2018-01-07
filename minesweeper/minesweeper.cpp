#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
  vector<vector<char> > updateBoard(vector<vector<char> >& board, vector<int>& click) {
    if (board.size() == 0)
      return board;
    if (board[click[0]][click[1]] == 'M') {
      board[click[0]][click[1]] = 'X';
      return board;
    } else if (board[click[0]][click[1]] == 'B' || (board[click[0]][click[1]]  > '0' && board[click[0]][click[1]] < '9'))
      return board;
    queue<vector<int> > q;
    q.push(click);
    vector<pair<int, int> > dirs = { make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1), make_pair(-1, -1), make_pair(-1, 1), make_pair(1, -1), make_pair(1, 1) };
    while (!q.empty()) {
      vector<int> v = q.front();
      q.pop();
      if (board[v[0]][v[1]] == 'B' || (board[v[0]][v[1]]  > '0' && board[v[0]][v[1]] < '9'))
	continue;
            
      int mineNum = 0;
      for (auto& dir : dirs) {
	int m = v[0] + dir.first;
	int n = v[1] + dir.second;
	if (m < 0 || m >= board.size() || n < 0 || n >= board[0].size())
	  continue;
	if (board[m][n] == 'M') {
	  mineNum++;
	}
      }
      if (mineNum == 0) {
	board[v[0]][v[1]] = 'B';
	for (auto& dir : dirs) {
	  int m = v[0] + dir.first;
	  int n = v[1] + dir.second;
	  if (m < 0 || m >= board.size() || n < 0 || n >= board[0].size() || board[m][n] != 'E')
	    continue;
	  vector<int> next;
	  next.push_back(m);
	  next.push_back(n);
	  q.push(next);
	}
      } else {
	board[v[0]][v[1]] = '0' + mineNum;
      }
    }
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
