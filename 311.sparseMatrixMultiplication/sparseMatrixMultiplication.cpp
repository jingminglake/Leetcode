#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>> res;
    int mA = A.size(), mB = B.size();
    if (mA == 0 || mB == 0)
      return res;
    int nA = A[0].size(), nB = B[0].size();
    res = vector<vector<int> >(mA, vector<int>(nB, 0));
    for (int i = 0; i < mA; i++) {
      for (int j = 0; j < nA; j++) {
	if (A[i][j] != 0) {
	  for (int k = 0; k < nB; k++) {
	    if (B[j][k] != 0)
	      res[i][k] += A[i][j] * B[j][k];
	  }
	}
      }
    }
    return res;
  }
};

int main()
{
  Solution s;
  vector<vector<int> > matrixA = {{1, 0, 0},
				  {-1, 0, 3}};
  vector<vector<int> > matrixB = {{7,0,0},
				  {0,0,0},
				  {0,0,1}};
  for ( auto& v : s.multiply(matrixA, matrixB) ) {
    for (int i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
