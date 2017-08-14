#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
  vector<vector<int> > updateMatrix(vector<vector<int> >& matrix) {
    int m = matrix.size();
    if (m == 0)
      return matrix;
    int n = matrix[0].size();
    queue<vector<int> > q;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
	if (matrix[i][j] == 0) {
	  vector<int> pos;
	  pos.push_back(i);
	  pos.push_back(j);
	  q.push(pos);
	} else {
	  matrix[i][j] = INT_MAX;
	}
      }
    }//for
    vector<pair<int, int> > dirs;
    dirs.push_back(make_pair(-1,0));
    dirs.push_back(make_pair(1,0));
    dirs.push_back(make_pair(0,-1));
    dirs.push_back(make_pair(0,1));
    while (!q.empty()) {
      vector<int> pos = q.front();
      q.pop();
      for (pair<int, int>& d : dirs) {
	int r = pos[0] + d.first;
	int c = pos[1] + d.second;
	if (r < 0 || r >= m || c < 0 || c >= n ||
	    matrix[r][c] <= matrix[pos[0]][pos[1]] + 1)
	  continue;
	vector<int> nextPos;
	nextPos.push_back(r);
	nextPos.push_back(c);
        q.push(nextPos);
	matrix[r][c] = matrix[pos[0]][pos[1]] + 1;  
      }
    }//while
    return matrix;
  }
};

int main()
{
  Solution s;
  int a1[3] = {0,0,0};
  int a2[3] = {0,1,0};
  int a3[3] = {1,1,1};
  vector<int> vec1(a1, a1+3);
  vector<int> vec2(a2, a2+3);
  vector<int> vec3(a3, a3+3);
  vector<vector<int> > matrix;
  matrix.push_back(vec1);
  matrix.push_back(vec2);
  matrix.push_back(vec3);
  s.updateMatrix(matrix);
  for (vector<int>& v : matrix) {
    for (int i : v)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}
