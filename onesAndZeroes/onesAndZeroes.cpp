// clang++ onesAndZeroes.cpp -std=c++11

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution{
public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
    for (string &str : strs) {
      int zeroes = 0, ones = 0;
      for (char &c : str) {
	if (c == '0')
	  zeroes++;
        else if (c == '1')
	  ones++;
      }
      for (int i = m; i >= zeroes; i--) {
	for (int j = n; j >= ones; j--) {
	  dp[i][j] = max(dp[i][j], dp[i - zeroes][j - ones] + 1);
	}//for
      }//for
    }//for
    return dp[m][n];
  }
};

int main()
{
  Solution s;
  vector<string> arr = {"10", "0001", "111001", "1", "0"};
  cout << s.findMaxForm(arr, 5, 3) << endl;
  return 0;
}
