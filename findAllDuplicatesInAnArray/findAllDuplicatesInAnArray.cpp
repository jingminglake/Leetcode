#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution{
public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
      int index = abs(nums[i]) - 1;
      if (nums[index] < 0)
	ans.push_back(index+1);
      else
	nums[index] = -nums[index];
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int a[8] = {4,3,2,7,8,2,3,1};
  vector<int> vec(a, a+8);
  vector<int> res = s.findDuplicates(vec);
  for (int i : res)
    cout << i << " ";
  cout << endl;
  return 0;
}
