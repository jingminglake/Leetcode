#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        vector<vector<double> > dp(A.size() , vector<double>(K + 1, -1));
        return helper(A, K, dp, A.size() - 1);
    }
    double helper(vector<int>& A, int K, vector<vector<double> >& dp, int i) {
        if (dp[i][K] > 0)
            return dp[i][K];
        if (K == 1) {
            double temp = 0;
            for (int m = 0; m <= i; m++)
                temp += A[m];
            return dp[i][K] = temp / (i + 1);
        }
        double res = 0, lastPart = A[i];
        for (int m = i - 1; m >= 0; m--) {
            res = max (res, (lastPart / (i - m) + helper(A, K - 1, dp, m) ));
            lastPart += A[m];
        }
        return dp[i][K] = res;
    }
};

int main() {
  Solution s;
  vector<int> A = {9,1,2,3,9};
  int K = 3;
  cout << s.largestSumOfAverages(A, K) << endl;
  return 0;
}
