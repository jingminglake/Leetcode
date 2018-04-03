#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() < 1)
            return;
        for (int i = 1; i < nums.size(); i++) {
            if (i % 2 != 0) {
                if (nums[i - 1] > nums[i])
                    swap(nums[i - 1], nums[i]);
            } else {
                if (nums[i - 1] < nums[i])
                    swap(nums[i - 1], nums[i]);
            }
        }
    }
};

int main() {
  Solution s;
  vector<int> nums = {3, 5, 2, 1, 6, 4};
  s.wiggleSort(nums);
  for (int n : nums)
    cout << n << " ";
  cout << endl;
  return 0;
}
