#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  void nextPermutation(vector<int>& nums) {
    int size = nums.size();
    int firstLessThan = size - 1;
    while (firstLessThan > 0 && nums[firstLessThan-1] >= nums[firstLessThan])
      firstLessThan--;
    if (firstLessThan == 0) {
      reverse(nums.begin(), nums.end());
      return;
    }
    firstLessThan--;
    int swapPoint = firstLessThan + 1;
    while (swapPoint < size-1 && nums[swapPoint+1] > nums[firstLessThan])
      swapPoint++;
    swap(nums[firstLessThan], nums[swapPoint]);
    reverse(nums.begin() + firstLessThan + 1 , nums.end());
  }
};

int main()
{
  Solution s;
  int a[6] = {1,5,1,4,3,1};
  vector<int> vec(a, a+3);
  s.nextPermutation(vec);
  vector<int>::iterator it = vec.begin();
  while (it != vec.end()) {
    cout << *it << " ";
    ++it;
  }
  cout << endl;
  return 0;
}
