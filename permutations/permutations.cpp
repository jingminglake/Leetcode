#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  vector<vector<int> > permute(vector<int>& nums) {
    vector<vector<int> > res;
    vector<int> path;
    dfs(res, path, nums);
    return res;
  }
  void dfs(vector<vector<int> >& res, vector<int>& path, vector<int>& nums) {
    if (path.size() == nums.size()) {
      res.push_back(path);
    }
    for (int i = 0; i < nums.size(); i++) {
      if (find(path.begin(), path.end(), nums[i]) != path.end()) {
	continue;
      }
      path.push_back(nums[i]);
      dfs(res, path, nums);
      path.pop_back();
    }
  }
};

int main()
{
  Solution s;
  int a[3] = {1,2,3};
  vector<int> vec(a, a+3);
  vector<vector<int> > res = s.permute(vec);
  vector<vector<int> >::iterator it = res.begin();
  while (it != res.end()) {
    for (int i : *it)
      cout << i << " ";
    cout << endl;
    ++it;
  }
  return 0;
}
