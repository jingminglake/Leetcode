#include <iostream>
#include <vector>
using namespace std;

class NumArray{
public:
  NumArray(vector<int> nums) {
    int sum = 0;
    for (int i : nums) {
      sum += i;
      p.push_back(sum);
    }
  }
 
  int sumRange(int i, int j) {
    if (i > j)
      return 0;
    if (i < 0)
      i = 0;
    if (j > p.size() - 1)
      j = p.size() - 1;
    if (i == 0)
      return p[j];
    else
      return p[j] - p[i-1];  
  }

  vector<int> p;
};

int main()
{
  int a[6] = {-2, 0, 3, -5, 2, -1};
  vector<int> vec(a, a+6);
  NumArray na(vec);
  cout << na.sumRange(2, 5) << endl;
  return 0;
}
