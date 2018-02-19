#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 1)
            return;
        int first = nums.size() - 2;
        while (first >= 0) {
            if (nums[first] >= nums[first + 1])
                first--;
            else
                break;
        }
        if (first == -1) {
            reverse(nums.begin(), nums.end());
            return ;
        }
        int swapPoint = nums.size() - 1;
        while (swapPoint > first) {
            if (nums[swapPoint] <= nums[first])
                swapPoint--;
            else
                break;
        }
        swap (nums[first], nums[swapPoint]);
        reverse(nums.begin() + first + 1, nums.end());
    }
};

int main()
{
  Solution s;
  int a[6] = {1,5,1,4,3,1};
  vector<int> vec(a, a+6);
  s.nextPermutation(vec);
  vector<int>::iterator it = vec.begin();
  while (it != vec.end()) {
    cout << *it << " ";
    ++it;
  }
  cout << endl;
  return 0;
}
