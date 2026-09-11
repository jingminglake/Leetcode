#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        vector<vector<double> > dp(A.size(), vector<double>(K + 1, -1));
        return dfs(A, K, A.size() - 1, dp);
    }
    // 0 ~ index is a sub-problem
    double dfs(vector<int>& A, int K, int index, vector<vector<double> >& dp) {
        if (dp[index][K] != -1)
            return dp[index][K];
        if (K == 1) {
            double sum = 0.0;
            for (int i = 0; i <= index; i++)
                sum += A[i];
            return dp[index][K] = sum / (index + 1);
        }
        if (index + 1 < K)
            return dp[index][K] = 0.0;
        double res = 0.0, lastPart = A[index];
        for (int i = index - 1; i >= 0; i--) {
            res = max (res, (lastPart / (index - i) + dfs(A, K - 1, i, dp)));
            lastPart += A[i];
        }
        return dp[index][K] = res;
    }
};

int main() {
    Solution s;
    vector<int> A = {9,1,2,3,9};
    int K = 3;
    cout << s.largestSumOfAverages(A, K) << endl;
    return 0;
}
