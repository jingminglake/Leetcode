// clang++ imageSmoother.cpp -std=c++11

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<vector<int> > imageSmoother(vector<vector<int> >& M) {
    int m = M.size();
    if (m <= 0)
      return M;
    int n = M[0].size();
    vector<vector<int> > M1 = M;
    vector<pair<int, int> > direction = {{-1,-1}, {0,-1}, {1,-1}, {1,0}, {1,1}, {0,1}, {-1,1}, {-1,0}};
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
	int sum = M[i][j];
	int numbers = 1;
	for (pair<int, int>& p : direction) {
	  int row = i + p.first;
	  int col = j + p.second;
	  if (row < 0 || row >= m || col < 0 || col >= n)
	    continue;
	  sum += M1[row][col];
	  numbers++;
	}//for
	M[i][j] = sum / numbers;
      }//for
    }//for
    return M;
  }
};

int main()
{
  Solution s;
  vector<int> vec0 = {1,1,1};
  vector<int> vec1 = {1,0,1};
  vector<int> vec2 = {1,1,1};
  vector<vector<int> > M;
  M.push_back(vec0);
  M.push_back(vec1);
  M.push_back(vec2);
  vector<vector<int> > res = s.imageSmoother(M);
  for (vector<int>& v : res) {
    for (int i : v)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}
