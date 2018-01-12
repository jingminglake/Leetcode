#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*class Compare {
public:
  bool operator()(tuple<int, int, int>& t1, tuple<int, int, int>& t2) const{
    return get<0>(t1) < get<0>(t2);
  };
  };*/

class Solution {
public:
  int cutOffTree(vector<vector<int> >& forest) {
    if (forest.size() == 0)
      return -1;
    vector<tuple<int, int, int> > trees;
    for (int i = 0; i < forest.size(); i++) {
      for (int j = 0; j < forest[0].size(); j++) {
	if (forest[i][j] != 0) {
	  trees.emplace_back(forest[i][j], i, j);
	}
      }
    }
    if (trees.size() == 0)
      return -1;
    sort(trees.begin(), trees.end());
    int res = bfs(forest, 0, 0, get<1>(trees[0]), get<2>(trees[0]) );
    if (res == -1)
      return res;
    for (int i = 1; i < trees.size(); i++) {
      int temp = bfs(forest, get<1>(trees[i-1]), get<2>(trees[i-1]), get<1>(trees[i]), get<2>(trees[i]));
      if (temp == -1)
	return -1;
      else {
	//cout << get<1>(trees[i-1]) << "  " << get<2>(trees[i-1]) 
	//     << "->" << get<1>(trees[i]) << "  " << get<2>(trees[i]) 
	//     << ": " <<  temp << endl;
	res += temp;
      }
    }
    return res;
  }
  int bfs(vector<vector<int> >& forest, int si, int sj, int di, int dj) {
    int dist = 0;
    if (si == di && sj == dj)
      return dist;
    vector<vector<bool> > visited(forest.size(), vector<bool>(forest[0].size(), false));
    queue<pair<int, int> > q;
    q.push(make_pair(si, sj));
    visited[si][sj] = true;
    vector<pair<int, int> > dirs = { make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1) };
    while (!q.empty()) {
      int size = q.size();
      dist++;
      for (int i = 0; i < size; i++) {
	pair<int, int>& p = q.front();
	q.pop();
	for (pair<int, int>& dir : dirs) {
	  int m = p.first + dir.first;
	  int n = p.second + dir.second;
	  if (m < 0 || m >= forest.size() || n < 0 || n >= forest[0].size() || forest[m][n] == 0 || visited[m][n])
	    continue;
	  if (m == di && n == dj) {
	    return dist;
	  }
	  q.push(make_pair(m, n));
	  visited[m][n] = true;
	}
      }
    }
    return -1;
  }
};



int main()
{
  Solution sl;
  vector<int> v1 = {1,2,3};
  vector<int> v2 = {0,0,4};
  vector<int> v3 = {7,6,5};
  vector<vector<int> > forest;
  forest.push_back(v1);
  forest.push_back(v2);
  forest.push_back(v3);
  cout << sl.cutOffTree(forest) << endl;
  return 0;
}
