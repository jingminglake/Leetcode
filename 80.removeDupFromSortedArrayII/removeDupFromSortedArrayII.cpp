#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0)
      return nums.size();
    int left = 0, right = 1;
    int count = 0;
    while (left < nums.size() && right < nums.size()) {
      if (nums[right] == nums[left]) {
	count++;
	if (count < 2) {
	  nums[++left] = nums[right];
	}
      } else {
	nums[++left] = nums[right];
	count = 0;
      }
      right++;
    }
    return left + 1;
  }
};

int main()
{
  Solution s;
  int a[6] = {1,1,1,1,2,3};
  vector<int> vec(a, a+6);
  cout << s.removeDuplicates(vec);
  cout << endl;
  return 0;
}
