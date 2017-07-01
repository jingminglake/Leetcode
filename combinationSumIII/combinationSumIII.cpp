#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  vector<vector<int> > combinationSum3(int k, int n) {
    vector<vector<int> > ans;
    vector<int> path;
    combinationSum3Helper(ans, k, n, path, 1);
    return ans;
  }
  void combinationSum3Helper(vector<vector<int> >& ans, int k, int target, vector<int>& path, int start) {
    if (!target && k == 0) {
      ans.push_back(path);
      return;
    }
    if (!k)
      return;
    for (int i = start; i < 10 && target >= i*k + k*(k-1)/2; i++) {
      path.push_back(i);
      combinationSum3Helper(ans, k - 1, target - i, path, i + 1);
      path.pop_back();
    }
  }
};

int main()
{
  Solution s;
  vector<vector<int> > res = s.combinationSum3(3, 7);
  for (vector<int> vec : res) {
    for (int i : vec)
      cout << i << " ";
    cout << endl;
  }
  cout << endl;
  return 0;
}
