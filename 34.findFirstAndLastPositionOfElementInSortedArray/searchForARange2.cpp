#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res = {-1, -1};
    if (nums.size() == 0)
      return res;
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] >= target) {
	right = mid - 1;
      } else if (nums[mid] < target) {
	left = mid + 1;
      }
    }
    if (left < nums.size() && nums[left] == target)
      res[0] = left;
    else
      return res;
    left++;
    right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] > target) {
	right = mid - 1;
      } else if (nums[mid] <= target) {
	left = mid + 1;
      }
    }
    if (nums[right] == target)
      res[1] = right;
    else
      res[1] = res[0];
    return res;
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
