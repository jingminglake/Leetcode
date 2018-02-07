#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    int size = candidates.size();
    vector<vector<int> > ans;
    vector<int> path;
    combinationSumHelper(ans, candidates, target, path, 0);
    return ans;
  }
  void combinationSumHelper(vector<vector<int> >& ans, vector<int>& candidates, int target, vector<int>& path, int start) {
    if (!target) {
      ans.push_back(path);
      return;
    }
    for (int i = start; i != candidates.size() && target >= candidates[i]; i++) {
      path.push_back(candidates[i]);
      combinationSumHelper(ans, candidates, target - candidates[i], path, i);
      path.pop_back();
    }
  }
};

int main()
{
  Solution s;
  int a[4] = {2,3,6,7};
  vector<int> vec(a, a+4);
  vector<vector<int> > res = s.combinationSum(vec, 7);
  for (vector<int> vec : res) {
    for (int i : vec)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}
