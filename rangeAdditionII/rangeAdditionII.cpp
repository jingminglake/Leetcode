#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int maxCount(int m, int n, vector<vector<int> >& ops) {
    //vector<vector<int> > matrix(m, vector<int>(n, 0));
    int row = m, col = n;
    for (vector<int> op : ops) {
      row = min(row, op[0]);
      col = min(col, op[1]);
    }
    return row*col;
  }
};

int main()
{
  Solution s;
  int a[2] = {2,2};
  int b[2] = {3,3};
  vector<int> vec1(a, a+2);
  vector<int> vec2(b, b+2);
  vector<vector<int> > ops;
  ops.push_back(vec1);
  ops.push_back(vec2);
  cout << s.maxCount(3, 3, ops) << endl;
  return 0;
}
