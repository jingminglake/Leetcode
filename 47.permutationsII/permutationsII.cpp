#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  vector<vector<int> > permute(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int> > ans;
    backtrack(nums, 0, nums.size(), ans);
    return ans;
  }
  void backtrack(vector<int> nums, int start, int size, vector<vector<int> >& ans) {
    if (size == start) {
      ans.push_back(nums);
      return;
    }
    for (int i = start; i < nums.size(); i++) {
      if (i != start && nums[i] == nums[start])
        continue;
      swap(nums[start], nums[i]);
      backtrack(nums, start+1, size, ans);
    }
  }
};

int main()
{
  Solution s;
  int a[4] = {1,2,1,2};
  vector<int> vec(a, a+4);
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
