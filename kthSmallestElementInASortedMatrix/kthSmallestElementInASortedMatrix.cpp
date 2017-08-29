// clang++ kthSmallestElementInASortedMatrix.cpp -std=c++11

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;


class Solution{
public:
  int kthSmallest(vector<vector<int> >& matrix, int k) {
    // method one : 65%
    int n = matrix.size();
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
	if (pq.size() < k) {
	  pq.push(matrix[i][j]);
	}
	else {
	  if (matrix[i][j] < pq.top()) {
	    pq.pop();
	    pq.push(matrix[i][j]);
	  }
	}
      }
    }//for
    return pq.top();
  }
};

int main()
{
  Solution s;
  vector<int> row1 = {1,5,9};
  vector<int> row2 = {10,11,13};
  vector<int> row3 = {12,13,15};
  vector<vector<int> > matrix;
  matrix.push_back(row1);
  matrix.push_back(row2);
  matrix.push_back(row3);
  cout << s.kthSmallest(matrix, 8);
  cout << endl;
  return 0;
}
