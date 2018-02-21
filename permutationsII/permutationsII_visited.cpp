#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        vector<int> path;
        vector<bool> visited(nums.size(), false);
        dfs(nums, res, 0, visited, path);
        return res;
    }
    void dfs(vector<int>& nums, vector<vector<int> >& res, int start, vector<bool>& visited, vector<int>& path) {
        if (start == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i])
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1] )
                continue;
            path.push_back(nums[i]);
            visited[i] = true;
            dfs (nums, res, start + 1, visited, path);
            path.pop_back();
            visited[i] = false;
        }
    }
};

int main()
{
  Solution s;
  int a[4] = {1,2,1,2};
  vector<int> vec(a, a+4);
  vector<vector<int> > res = s.permuteUnique(vec);
  vector<vector<int> >::iterator it = res.begin();
  while (it != res.end()) {
    for (int i : *it)
      cout << i << " ";
    cout << endl;
    ++it;
  }
  return 0;
}
