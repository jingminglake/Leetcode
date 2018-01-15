#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  vector<vector<int> > permute(vector<int>& nums) {
    vector<vector<int> > ans;
    backtrack(nums, 0, ans);
    return ans;
  }
  void backtrack(vector<int>& nums, int start, vector<vector<int> >& ans) {
    if (nums.size() == start) {
      ans.push_back(nums);
      return;
    }
    for (int i = start; i < nums.size(); i++) {
      swap(nums[start], nums[i]);
      backtrack(nums, start+1, ans);
      swap(nums[start], nums[i]);
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
