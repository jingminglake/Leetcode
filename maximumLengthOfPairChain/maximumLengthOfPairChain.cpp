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
    int size = pairs.size();
    if (size == 0)
      return 0;
    sort(pairs.begin(), pairs.end(), Compare());
    vector<int> dp(size, 1);
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < i; j++) {
	dp[i] = max(dp[i], pairs[j][1] < pairs[i][0] ? dp[j] + 1 : dp[j]);
      }
    }
    return dp[size - 1];
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
