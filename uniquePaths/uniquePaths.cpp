// clang++ uniquePaths.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int uniquePaths(int m, int n) {
    if (m < 0 || n < 0)
      return 0;
    if (m > n)
      return uniquePaths(n, m);
    vector<int> cur(m, 1);
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
	cur[j] += cur[j - 1];
      }
    }//for
    return cur[m - 1];
  }
};

int main()
{
  Solution s;
  cout << s.uniquePaths(2,1) << endl;;
  return 0;
}
