// clang++ guessNumberHigherOrLowerII.cpp -std=c++11

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
  int getMoneyAmount(int n) {
    vector<vector<int> > hash(n + 1, vector<int>(n + 1, 0));
    return getMoneyAmountHelper(hash, 1, n);
  }
  int getMoneyAmountHelper(vector<vector<int> > &hash, int start, int end) {
    if (start >= end)
      return 0;
    if (hash[start][end] != 0)
      return hash[start][end];
    int res = INT_MAX;
    for (int x = start; x <= end; x++) {
      res = min (res, x + max(getMoneyAmountHelper(hash, start, x - 1), getMoneyAmountHelper(hash, x + 1, end)));
    }
    hash[start][end] = res;
    return res;
  }
};

int main()
{
  Solution s;
  vector<vector<int> > pairs = {{1, 2},
				{2, 3},
                                {3, 4}};
  cout << s.getMoneyAmount(10) << endl;
  return 0;
}
