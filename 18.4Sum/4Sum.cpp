#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<vector<int> > fourSum(vector<int>& nums, int target) {
    vector<vector<int> > ans;
    if (nums.size() < 4)
      return ans;
    sort(nums.begin(), nums.end());
    int size = nums.size();
    for (int i = 0; i < size - 3; i++) {
      for (int j = i + 1; j < size - 2; j++) {
	int val = target - nums[i] - nums[j];
	int left = j + 1, right = size - 1;
	while (left < right) {
	  if (nums[left] + nums[right] < val) {
	    left++;
          }
	  else if (nums[left] + nums[right] > val) {
	    right--;
	  }
	  else {
	    vector<int> temp(4, 0);
	    temp[0] = nums[i];
	    temp[1] = nums[j];
	    temp[2] = nums[left];
	    temp[3] = nums[right];
	    ans.push_back(temp);
	    while (left < right && nums[left] == temp[2])
	      left++;
	    while (left < right && nums[right] == temp[3])
	      right--;
	  }
	}//while
	while (j + 1 < nums.size() && nums[j + 1] == nums[j])
	  j++;
      }//for
      while (i + 1 < nums.size() && nums[i + 1] == nums[i])
	i++;
    }//for
    return ans;
  }
};

int main()
{
  Solution s;
  int a[8] = {-1, -5, -5, -3, 2, 5, 0, 4};
  vector<int> nums(a, a+8);
  vector<vector<int> > vec = s.fourSum(nums, -7);
  vector<vector<int> >::iterator it = vec.begin();
  while (it != vec.end()) {
    vector<int>::iterator it2 = (*it).begin();
    while (it2 != (*it).end()) {
      cout << *it2 << " ";
      ++it2;
    }
    cout << endl;
    ++it;
  }
  return 0;
}
