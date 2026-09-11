#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
  vector<vector<int> > permuteUnique(vector<int>& nums) {
    set<vector<int> > res;
    sort(nums.begin(), nums.end());
    dfs(nums, res, 0);
    return vector<vector<int> >(res.begin(), res.end());
  }
  void dfs(vector<int>& nums, set<vector<int> >& res, int start) {
    if (start == nums.size()) {
      res.insert(nums);
      return;
    }
    for (int i = start; i < nums.size(); i++) {
      if (i != start && nums[i] == nums[start])
	continue;
      swap(nums[start], nums[i]);
      dfs (nums, res, start + 1);
      swap(nums[start], nums[i]);
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
