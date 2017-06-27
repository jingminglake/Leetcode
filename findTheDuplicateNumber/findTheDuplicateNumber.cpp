#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int findDuplicate(vector<int>& nums) {
    int size = nums.size();
    if (size <= 1)
      return -1;
    int slow = nums[0];
    int fast = nums[nums[0]];
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }
    fast = 0;
    while (fast != slow) {
      fast = nums[fast];
      slow = nums[slow];
    }
    return slow;
  }
};

int main()
{
  Solution s;
  int a[4] = {1,2,3,1};
  vector<int> vec(a, a+2);
  cout <<  s.findDuplicate(vec);
  cout << endl;
  return 0;
}
