#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  int findMaxLength(vector<int>& nums) {
    int res = 0;
    unordered_map<int, int> m;
    m[0] = -1;
    int preSum = 0;
    for (int i = 0; i < nums.size(); i++) {
      int num = (nums[i] == 0 ? -1 : 1);
      preSum += num;
      if (m.count(preSum)) {
	res = max (res, i - m[preSum]);
      } else {
	m[preSum] = i; 
      }
    }
    return res;
  }
};

int main()
{
  Solution s;
  int a[7] = {0, 0, 1, 0};
  vector<int> vec(a, a+4);
  cout << s.findMaxLength(vec);
  cout << endl;
  return 0;
}
