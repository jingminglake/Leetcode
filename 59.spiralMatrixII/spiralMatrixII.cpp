// clang++ spiralMatrixII.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
  vector<vector<int> > generateMatrix(int n) {
    vector<vector<int> > ans(n, vector<int>(n,0)); 
    int rowBegin = 0, rowEnd = n - 1;
    int colBegin = 0, colEnd = n - 1;
    int num = 1;
    while (rowBegin <= rowEnd && colBegin <= colEnd) {
      // traverse Right
      for (int i = colBegin; i <= colEnd; i++) {
	ans[rowBegin][i] = num++;
      }
      rowBegin++;
      // traverse Down
      for (int i = rowBegin; i <= rowEnd; i++) {
	ans[i][colEnd] = num++;
      }
      colEnd--;
      if (rowBegin <= rowEnd) {
	// traverse Left
	for (int i = colEnd; i >= colBegin; i--) {
	  ans[rowEnd][i] = num++;
	}
	rowEnd--;
      }
      if (colBegin <= colEnd) {
	//travese up
	for (int i = rowEnd; i >= rowBegin; i--) {
	  ans[i][colBegin] = num++;
	}
	colBegin++;
      }
    }//while
    return ans;
  }
};

int main()
{
  Solution s;
  vector<vector<int> > res = s.generateMatrix(3);
  for (vector<int>& vec : res) {
    for (int i : vec) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
