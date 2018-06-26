#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        vector<vector<double> > dp(A.size() , vector<double>(K + 1, -1));
        return helper(A, K, dp, A.size() - 1);
    }
    double helper(vector<int>& A, int K, vector<vector<double> >& dp, int end) {
        if (dp[end][K] > 0)
            return dp[end][K];
        if (K == 1) {
            double temp = 0;
            for (int i = 0; i <= end; i++)
                temp += A[i];
            return dp[end][K] = temp / (end + 1);
        }
        if (K > end + 1)
            return dp[end][K] = 0;
        double res = 0, lastPart = A[end];
        for (int i = end - 1; i >= 0; i--) {
            res = max (res, (lastPart / (end - i) + helper(A, K - 1, dp, i) ));
            lastPart += A[i];
        }
        return dp[end][K] = res;
    }
};

int main() {
    Solution s;
    vector<int> A = {9,1,2,3,9};
    int K = 3;
    cout << s.largestSumOfAverages(A, K) << endl;
    return 0;
}
