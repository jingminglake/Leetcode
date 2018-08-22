// clang++ onesAndZeroes.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        for (string& str : strs) {
            int num_of_zeroes = 0, num_of_ones = 0;
            for (char c : str) {
                if (c == '0')
                    num_of_zeroes++;
                else if (c == '1')
                    num_of_ones++;
            }
            for (int i = m; i >= num_of_zeroes; i--) {
                for (int j = n; j >= num_of_ones; j--) {
                    dp[i][j] = max (dp[i][j], dp[i - num_of_zeroes][j - num_of_ones] + 1);
                }
            }
        }
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
