#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution{
public:
  int thirdMax(vector<int>& nums) {
    int firstMax = INT_MIN, secondMax = INT_MIN, thirdMax = INT_MIN;
    int size = nums.size();
    set<int> set;
    for (int i = 0; i < size; i++) {
      set.insert(nums[i]);
      if (nums[i] == firstMax || nums[i] == secondMax || nums[i] == thirdMax)
	continue;
      if (nums[i] > firstMax) {
	thirdMax = secondMax;
	secondMax = firstMax;
	firstMax = nums[i];
      }
      else if (nums[i] > secondMax) {
	thirdMax = secondMax;
	secondMax = nums[i];
      }
      else if (nums[i] > thirdMax) {
	thirdMax = nums[i];
      }
    }
    if (thirdMax == INT_MIN && set.size() < 3) 
      return firstMax;
    return thirdMax;
  }
};

int main()
{
  Solution s;
  int a[8] = {1,2,-2147483648,5,3,5,9,10};
  vector<int> vec(a, a+3);
  cout << s.thirdMax(vec) << endl;
 
  return 0;
}
