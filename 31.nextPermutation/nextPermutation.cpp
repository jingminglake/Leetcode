#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        int i = nums.size() - 1;
        while (i > 0) {
            if (nums[i - 1] < nums[i])
                break;
            i--;
        }
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int firstBigger = nums.size() - 1;
        while (firstBigger >= i) {
            if (nums[firstBigger] > nums[i - 1])
                break;
            firstBigger--;
        }
        swap(nums[firstBigger], nums[i - 1]);
        reverse(nums.begin() + i, nums.end());
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
