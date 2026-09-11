#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int numberOfArithmeticSlices(vector<int>& A) {
    int size = A.size();
    int res = 0, cur = 0;
    for (int i = 2; i < size; i++) {
      if (A[i] - A[i-1] == A[i-1] - A[i-2]) {
	cur++;
	res += cur;
      } else {
	cur = 0;
      }
    }
    return res;
  }
};

int main()
{
  Solution s;
  int a[4] = {1,2,3,4};
  vector<int> vec(a, a+4);
  cout << s.numberOfArithmeticSlices(vec) << endl;
  return 0;
}
