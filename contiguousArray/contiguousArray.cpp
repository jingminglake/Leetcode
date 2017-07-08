#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution{
public:
  int findMaxLength(vector<int>& nums) {
    int maxL = INT_MIN;
    int size = nums.size();
    if (size < 1)
      return 0;
    unordered_map<int, int> m;
    m.insert(make_pair(0, -1));
    int preSum = 0;
    for (int i = 0; i < size; i++) {
      preSum += nums[i] == 1 ? 1 : -1;
      unordered_map<int, int>::iterator it = m.find(preSum);
      if (it != m.end()) {
	maxL = max(maxL, i - it->second);
      } else {
	m.insert(make_pair(preSum, i));
      }
    }
    return maxL == INT_MIN ? 0 : maxL;
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
