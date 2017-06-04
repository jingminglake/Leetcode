#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int findUnsortedSubarray(vector<int>& nums) {
    int left = 0, right = -1;
    int size = nums.size();
    int maxE = nums[0], minE = nums[size - 1];
    for (int i = 1; i < size; i++) {
      minE = min(nums[size-i-1], minE);
      if (nums[size-i-1] > minE)
	left = size-i-1;
      maxE = max(nums[i], maxE);
      if (nums[i] < maxE)
	right = i;
    }
    cout << left << " " << right << endl;
    return right - left + 1;
  }
};

int main()
{
  Solution s;
  int a[7] = {2,6,4,8,10,9,15};
  vector<int> vec(a, a+7);
  cout << s.findUnsortedSubarray(vec) << endl;
 
  return 0;
}
