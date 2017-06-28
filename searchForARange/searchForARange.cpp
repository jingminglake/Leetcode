#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans(2, -1);
    int size = nums.size();
    if (size == 0)
      return ans;
    int left = 0, right = size - 1;
    int mid = 0;
    while (left < right) {
      mid = left + (right-left)/2;
      if (nums[mid] < target)
	left = mid + 1;
      else
	right = mid;
    }
    cout << left << "--1--" << right << endl;
    if (nums[left] == target)
      ans[0] = left;
    right = size - 1;
    while (left < right) {
      mid = left + (right-left)/2 + 1;
      if (nums[mid] <= target)
	left = mid;
      else
	right = mid - 1;
    }
    cout << left << "--2--" << right << endl;
    if (nums[left] == target)
      ans[1] = left;
    return ans;
  }
};

int main()
{
  Solution s;
  int a[9] = {5,7,7,8,8,8,8,10,11};
  vector<int> vec(a, a+9);
  vector<int> res = s.searchRange(vec, 8);
  for (int num : res)
    cout << num << " ";
  cout << endl;
  return 0;
}
