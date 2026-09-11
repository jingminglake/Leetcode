#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > ans;
    vector<int> tempList;
    backtrack(n, k, 1, tempList, ans);
    return ans;
  }
  void backtrack(int n, int k, int start, vector<int>& tempList, vector<vector<int> >& ans) {
    // if (n == start || tempList.size() > k) {
    if (tempList.size() == k) {
	ans.push_back(tempList);
	return;
    }
    for (int i = start; i <= n; i++) {
	tempList.push_back(i);
	backtrack(n, k, i+1, tempList, ans);
	tempList.pop_back();
    }
  }
};

int main()
{
  Solution s;
  vector<vector<int> > res = s.combine(4, 2);
  vector<vector<int> >::iterator it = res.begin();
  while (it != res.end()) {
    for (int i : *it)
      cout << i << " ";
    cout << endl;
    ++it;
  }
  return 0;
}
