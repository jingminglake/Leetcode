// clang++ maximumLengthOfPairChain.cpp -std=c++11

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Compare {
public:
  bool operator()(const vector<int>& v1, const vector<int>& v2) const {
    return v2[0] > v1[0];
  }
};

class Solution {
public:
  int findLongestChain(vector<vector<int> >& pairs) {
    int dp[pairs.size()];
    fill_n(dp, pairs.size(), 1);
    int res = 1;
    sort(pairs.begin(), pairs.end(), Compare());
    for (int i = 1; i < pairs.size(); i++) {
      for (int j = 0; j < i; j++) {
	if (pairs[j][1] < pairs[i][0])
	  dp[i] = max(dp[i], dp[j] + 1);
      }
      res = max(res, dp[i]);
    }
    return res;
  }
};

int main()
{
  Solution s;
  vector<vector<int> > pairs = {{1, 2},
				{2, 3},
                                {3, 4}};
  cout << s.findLongestChain(pairs) << endl;
  return 0;
}
