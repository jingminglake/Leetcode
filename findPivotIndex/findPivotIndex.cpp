#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int pivotIndex(vector<int>& nums) {
    int size = nums.size();
    if (size == 0)
      return -1;
    int sum = 0;
    for (int n : nums)
      sum += n;
    int leftP = 0;
    for (int i = 0; i < size; i++) {
      leftP += nums[i];
      if (sum - leftP == leftP - nums[i])
	return i;
    }
    return -1;
  }
};

int main()
{
  Solution s;
  vector<int> ss = {1,7,3,6,5,6};
  vector<int> ss1 = {1};
  vector<int> ss2 = {1,2,3};
  cout << s.pivotIndex(ss) << endl;
  cout << s.pivotIndex(ss1) << endl;
  cout << s.pivotIndex(ss2) << endl;
  return 0;
}
