#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int countArrangement(int N) {
    int ans = 0;
    vector<int> used(N+1, 0);
    backtrack(N, 1, used, ans);
    return ans;
  }
  void backtrack(int n, int pos, vector<int>& used, int& ans) {
    if (pos > n) {
      ans++;
      return;
    }
    for (int i = 1; i <= n; i++) {
      if (used[i] == 0 && (pos % i == 0 || i % pos == 0)) {
	used[i] = 1;
	backtrack(n, pos+1, used, ans);
	used[i] = 0;
      }
    }
  }
};

int main()
{
  Solution s;
  cout << s.countArrangement(3);
  cout << endl;
  return 0;
}
