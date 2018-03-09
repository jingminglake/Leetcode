#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int res = 0;
        if (nums.size() < 3)
            return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] < target - nums[i]) {
                    res += right - left;
                    left++;
                } else {
                    right--;
                }
            }
        }
        return res;
    }
};

int main()
{
  Solution s;
  int a[6] = {-1, 0, 1, 2, -1, -4};
  vector<int> nums(a, a+6);
  cout << s.threeSumSmaller(nums, 0) << endl;
  return 0;
}
