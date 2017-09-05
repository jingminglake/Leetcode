// clang++ gameOfLife.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  void gameOfLife(vector<vector<int> >& board) {
    int m = board.size();
    if (m == 0)
      return;
    int n = board[0].size();
    vector<pair<int, int> > dirs = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
	int liveNum = 0;
	for (pair<int, int>& d : dirs) {
	  int r = i + d.first;
	  int c = j + d.second;
	  if (r < 0 || r >= m || c < 0 || c >= n)
	    continue;
	  if ((board[r][c] & 1) == 1)
	    liveNum++;
	}
        if (board[i][j] == 1 && (liveNum == 2 || liveNum == 3))
	  board[i][j] = 3; // 3 <=> 11 : 1<-1 live to live
	else if (board[i][j] == 0 && liveNum == 3)
	  board[i][j] = 2; // 2 <=> 10 : 1<-0 dead to live(reproduction)
	//else if (board[i][j] == 1 && (liveNum < 2 || liveNum > 3))
	//  board[i][j] = 1; // 1 <=> 01 : 0<-1 live to dead
	//else if (board[i][j] == 0)
	//board[i][j] = 0; // 0 <=> 00 : 0<-0 dead to dead
      }
    }//for

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
	/*if (board[i][j] == 2 || board[i][j] == 3)
	  board[i][j] = 1;
	else if (board[i][j] == 0 || board[i][j] == 1)
	board[i][j] = 0;*/
	board[i][j] >>= 1;
      }
    }//for
    
  }
};

int main()
{
  Solution s;
  int a1[4] = {0,0,0,0};
  int a2[4] = {0,1,0,1};
  int a3[4] = {1,0,1,0};
  int a4[4] = {0,0,0,1};
  vector<int> vec1(a1, a1+4);
  vector<int> vec2(a2, a2+4);
  vector<int> vec3(a3, a3+4);
  vector<int> vec4(a4, a4+4);
  vector<vector<int> > matrix;
  matrix.push_back(vec1);
  matrix.push_back(vec2);
  matrix.push_back(vec3);
  matrix.push_back(vec4);
  s.gameOfLife(matrix);
  for (vector<int>& v : matrix) {
    for (int i : v)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}
