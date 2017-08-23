// clang++ matchsticksToSquare.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int findCircleNum(vector<vector<int> >& M) {
    int ans = 0;
    int n = M.size();
    if (n <= 0)
      return ans;
    if (n != M[0].size())
      return ans;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
	dfs(M, i, visited);
	ans++;
      }
    }
    return ans;
  }
  void dfs(vector<vector<int> >& M, int index, vector<bool>& visited) {
    int size = M[index].size();
    for (int j = 0; j < size; j++) {
	if (!visited[j] && M[index][j] == 1) {
	  visited[j] = true;
	  dfs(M, j, visited);
	}
      }
  }
};

int main()
{
  Solution s;
  vector<int> vec0 = {1,1,0};
  vector<int> vec1 = {1,1,1};
  vector<int> vec2 = {0,1,1};
  vector<vector<int> > M;
  M.push_back(vec0);
  M.push_back(vec1);
  M.push_back(vec2);
  cout << s.findCircleNum(M);
  cout << endl;
  return 0;
}
