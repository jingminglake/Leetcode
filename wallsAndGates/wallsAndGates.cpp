#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    if (rooms.size() == 0)
      return;
    queue<pair<int, int> > q;
    for (int i = 0; i < rooms.size(); i++) {
      for (int j = 0; j < rooms[0].size(); j++) {
	if (rooms[i][j] == 0) {
	  q.push(make_pair(i, j));
	}
      }
    }
    int dist = 0;
    vector<pair<int, int> > dirs = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, 1), make_pair(0, -1)};
    while (!q.empty()) {
      dist++;
      int size = q.size();
      for (int i = 0; i < size; i++) {
	pair<int, int> temp = q.front();
	q.pop();
	for (pair<int, int>& dir : dirs) {
	  int m = temp.first + dir.first;
	  int n = temp.second + dir.second;
	  if (m < 0 || m >= rooms.size() || n < 0 || n >= rooms[0].size() || rooms[m][n] != INT_MAX)
	    continue;
	  rooms[m][n] = dist;
	  q.push(make_pair(m, n));
	}
      }
    }// while
  }
};

int main()
{
  Solution s;
  int a1[4] = {INT_MAX,-1,0, INT_MAX};
  int a2[4] = {INT_MAX,INT_MAX,INT_MAX,-1};
  int a3[4] = {INT_MAX,-1,INT_MAX,-1};
  int a4[4] = {0,-1,INT_MAX,INT_MAX};
  vector<int> vec1(a1, a1+4);
  vector<int> vec2(a2, a2+4);
  vector<int> vec3(a3, a3+4);
  vector<int> vec4(a4, a4+4);
  vector<vector<int> > matrix;
  matrix.push_back(vec1);
  matrix.push_back(vec2);
  matrix.push_back(vec3);
  matrix.push_back(vec4);
  s.wallsAndGates(matrix);
  for (vector<int>& v : matrix) {
    for (int i : v)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}
