#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution{
public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ans;
    int size = nums.size();
    if (size < 1)
      return ans;
    for (int i = 0; i < size; i++) {
      int index = abs(nums[i]) - 1;
      if (nums[index] > 0)
	nums[index] = -nums[index];
    }
    for (int j = 0; j < size; j++) {
      if (nums[j] > 0)
	ans.push_back(j + 1);
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int a[8] = {4,3,2,7,8,2,3,1};
  vector<int> vec(a, a+8);
  vector<int> vec2 = s.findDisappearedNumbers(vec);
  vector<int>::iterator it = vec2.begin();
  while (it != vec2.end()) {
    cout << *it << " ";
    ++it;
  }
  cout << endl;
  return 0;
}
