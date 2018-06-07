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
    backTracking(nums, 0, subset, ans);
    return ans;
  }
  void backTracking(vector<int>& nums, int start, vector<int>& subset, vector<vector<int> >& ans) {
    ans.push_back(subset);
    for (int i = start; i < nums.size(); i++) {
      subset.push_back(nums[i]);
      backTracking(nums, i + 1, subset, ans);
      subset.pop_back();
    }
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
