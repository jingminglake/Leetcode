// clang++ increasingSubsequence.cpp -std=c++11

#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;

class Solution{
public:
  vector<vector<int> > findSubsequences(vector<int>& nums) {
    //sort(nums.begin(), nums.end);
    vector<vector<int> > ans;
    vector<int> path;
    set<vector<int> > ansSet;
    dfs(nums, ansSet, path, 0);
    set<vector<int> >::iterator it = ansSet.begin();
    while (it != ansSet.end()) {
      ans.push_back(*it);
      ++it;
    }
    return ans;
  }
  void dfs(vector<int>& nums, set<vector<int> >& ansSet, vector<int>& path, int start) {
    if (path.size() >= 2) {
      ansSet.insert(path);
    }
    int size = nums.size();
    for (int i = start; i < size; i++) {
      if (path.size() == 0 || path.back() <= nums[i]) {
	path.push_back(nums[i]);
	dfs(nums, ansSet, path, i + 1);
	path.pop_back();
      }
    }
  }
};

int main()
{
  Solution s;
  vector<int> vec = {4,6,7,7};
  vector<vector<int> > res = s.findSubsequences(vec);
  for (vector<int>& v : res) {
    for (int i : v)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}
