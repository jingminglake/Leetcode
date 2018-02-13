#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int res = 0;
        vector<vector<int> > dp(N, vector<int>(N, N));
        for (int i = 0; i < mines.size(); i++) {
            dp[mines[i][0]][mines[i][1]] = 0;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0, l = 0; j < N; j++) {
                l = dp[i][j] == 0 ? 0 : l + 1;
                dp[i][j] = min (dp[i][j], l);
            }
            for (int j = N - 1, r = 0; j >= 0; j--) {
                r = dp[i][j] == 0 ? 0 : r + 1;
                dp[i][j] = min (dp[i][j], r);
            }
            for (int j = 0, u = 0; j < N; j++) {
                u = dp[j][i] == 0 ? 0 : u + 1;
                dp[j][i] = min (dp[j][i], u);
            }
            for (int j = N - 1, d = 0; j >= 0; j--) {
                d = dp[j][i] == 0 ? 0 : d + 1;
                dp[j][i] = min (dp[j][i], d);
            }
        }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                res = max (res, dp[i][j]);
        return res;
    }
};

int main()
{
  Solution s;
  vector<vector<int> > mines = {{4,2}};
  cout << s.orderOfLargestPlusSign(5, mines);
  cout << endl;
  return 0;
}
