#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    int size = candidates.size();
    sort(candidates.begin(), candidates.end());
    vector<vector<int> > ans;
    vector<int> path;
    combinationSum2Helper(ans, candidates, target, path, 0);
    return ans;
  }
  void combinationSum2Helper(vector<vector<int> >& ans, vector<int>& candidates, int target, vector<int>& path, int start) {
    if (!target) {
      ans.push_back(path);
      return;
    }
    for (int i = start; i != candidates.size() && target >= candidates[i]; i++) {
      if (i == start || candidates[i] != candidates[i - 1]) {
	path.push_back(candidates[i]);
	combinationSum2Helper(ans, candidates, target - candidates[i], path, i + 1);
	path.pop_back();
      }
    }
  }
};

int main()
{
  Solution s;
  int a[7] = {10,1,2,7,6,1,5};
  vector<int> vec(a, a+7);
  vector<vector<int> > res = s.combinationSum2(vec, 8);
  for (vector<int> vec : res) {
    for (int i : vec)
      cout << i << " ";
    cout << endl;
  }
  cout << endl;
  return 0;
}
