#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int rob(vector<int>& nums) {
    int size = nums.size();
    if (size == 0)
      return 0;
    if (size == 1)
      return nums[0];
    vector<int> m(size, 0);
    m[0] = nums[0];
    m[1] = nums[1];
    int maxA = max(m[0], m[1]);
    for (int i = 2; i < size; i++) {
      int maxM = m[0];
      for (int j = 1; j < i - 1; j++) {
	if (m[j] > maxM) {
	  maxM = m[j];
        }
      }
      m[i] =  maxM + nums[i];
      maxA = max(maxA, m[i]);
    }
    return maxA;
  }
};

int main()
{
  int a[6] = {0, 0, 3, 0, 2, 0};
  vector<int> vec(a, a+6);
  Solution s;
  cout << s.rob(vec) << endl;
  return 0;
}
