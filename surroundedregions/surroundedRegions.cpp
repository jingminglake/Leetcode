#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
  void solve(vector<vector<char> >& board) {
    int m = board.size();
    if (m == 0)
      return;
    int n = board[0].size();
    queue<vector<int> > q;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
	if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j] == 'O') {
	  vector<int> pos;
	  pos.push_back(i);
	  pos.push_back(j);
	  q.push(pos);
	  board[i][j] = '1';
	}
      }
    }//for
    vector<pair<int, int> > dirs;
    dirs.push_back(make_pair(-1, 0));
    dirs.push_back(make_pair(0, -1));
    dirs.push_back(make_pair(0, 1));
    dirs.push_back(make_pair(1, 0));
    while (!q.empty()) {
      vector<int> pos = q.front();
      q.pop();
      for (pair<int, int>& d : dirs) {
	int r = pos[0] + d.first;
	int c = pos[1] + d.second;
	if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] == 'X' || board[r][c] == '1')
	  continue;
	if (board[r][c] == 'O') {
	  vector<int> temp;
	  temp.push_back(r);
	  temp.push_back(c);
	  q.push(temp);
	  board[r][c] = '1';
	}
      }
    }//while
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
	if (board[i][j] == 'O')
	  board[i][j] = 'X';
	if (board[i][j] == '1')
	  board[i][j] = 'O';
      }
    }//for
  }
};

int main()
{
  Solution s;
  char a1[4] = {'X','X','X','X'};
  char a2[4] = {'X','O','O','X'};
  char a3[4] = {'X','X','O','X'};
  char a4[4] = {'X','O','X','X'};
  vector<char> vec1(a1, a1+4);
  vector<char> vec2(a2, a2+4);
  vector<char> vec3(a3, a3+4);
  vector<char> vec4(a4, a4+4);
  vector<vector<char> > board;
  board.push_back(vec1);
  board.push_back(vec2);
  board.push_back(vec3);
  board.push_back(vec4);
  s.solve(board);
  for (vector<char>& v : board) {
    for (char i : v)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}
