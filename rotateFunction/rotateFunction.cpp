#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxRotateFunction(vector<int>& A) {
    int sum = 0;
    int len = A.size();
    int F = 0;
    for (int i = 0; i < len; i++) {
      F += i * A[i];
      sum += A[i];
    }
    int res = F;
    for (int i = len - 1; i >= 1; i--) {
      F = F + sum - len * A[i];
      res = max(F, res);
    }
    return res;   
  }
};

int main()
{
  Solution s;
  vector<int> A = {4,3,2,6};
  cout << s.maxRotateFunction(A);
  cout << endl;
  return 0;
}
