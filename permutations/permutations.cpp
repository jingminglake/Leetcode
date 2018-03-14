#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > res;
        vector<bool> visited(nums.size(), false);
        vector<int> path;
        dfs(nums, visited, path, res);
        return res;
    }
    void dfs(vector<int>& nums, vector<bool>& visited, vector<int>& path, vector<vector<int> >& res) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i])
                continue;
            visited[i] = true;
            path.push_back(nums[i]);
            dfs(nums, visited, path, res);
            path.pop_back();
            visited[i] = false;
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
