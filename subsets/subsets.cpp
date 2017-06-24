#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  vector<vector<int> > subsets(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int> > ans;
    vector<int> subset;
    genSubsets(nums, 0, subset, ans);
    return ans;
  }
  void genSubsets(vector<int>& nums, int level, vector<int>& subset, vector<vector<int> >& ans) {
    if (level == nums.size()) {
      ans.push_back(subset);
      return;
    }
    subset.push_back(nums[level]);
    genSubsets(nums, level+1, subset, ans);
    subset.pop_back();
    genSubsets(nums, level+1, subset, ans);
    return;
  }
};

int main()
{
  Solution s;
  int a[3] = {1,2,3};
  vector<int> vec(a, a+3);
  vector<vector<int> > res = s.subsets(vec);
  vector<vector<int> >::iterator it = res.begin();
  while (it != res.end()) {
    for (int i : *it)
      cout << i << " ";
    cout << endl;
    ++it;
  }
  return 0;
}
