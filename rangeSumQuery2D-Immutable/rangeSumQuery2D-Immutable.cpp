// clang++ rangeSumQuery2D-Immutable.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
public:
  NumMatrix(vector<vector<int> > matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0)
      return;
    int m = matrix.size();
    int n = matrix[0].size();
    dp = vector<vector<int> >(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
	dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
      }
    }
  }
  int sumRegion(int row1, int col1, int row2, int col2) {
    return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
  }
private:
  vector<vector<int> > dp;
};

int main()
{
  vector<vector<int> > matrix = {{3,0,1,4,2},
				 {5,6,3,2,1},
                                 {1,2,0,1,5},
                                 {4,1,0,1,7},
                                 {1,0,3,0,5}};
  NumMatrix objMatrix(matrix);
  cout << objMatrix.sumRegion(2,1,4,3) << endl;
  cout << objMatrix.sumRegion(1,1,2,2) << endl;
  cout << objMatrix.sumRegion(1,2,2,4) << endl;
  return 0;
}
