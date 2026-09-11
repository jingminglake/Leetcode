#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<vector<int> > getFactors(int n) {
    vector<vector<int> > res;
    vector<int> path;
    dfs(n, 2, res, path);
    return res;
  }
  void dfs(int n, int start, vector<vector<int> >& res, vector<int>& path) {
    if (n <= 1) {
      if (path.size() > 1)
	res.push_back(path);
      return;
    }
    for (int i = start; i <= n; i++) {
      if (n % i == 0) {
	path.push_back(i);
	dfs(n / i, i, res, path);
	path.pop_back();
      }
    }
  }
};

int main()
{
  Solution s;
  for (vector<int>& res : s.getFactors(32)) {
    for (int vec : res)
      cout << vec << " ";
    cout << endl;
  }
  return 0;
}
