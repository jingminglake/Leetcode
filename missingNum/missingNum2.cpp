#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution{
public:
  int missingNumber(vector<int>& nums) {
    int res = nums.size();
    if (nums.size() == 0)
      return 0;
    for (int i = 0; i < nums.size(); i++) {
      res = res ^ i;
      res = res ^ nums[i];
    }
    return res;
  }
};

int main()
{
  Solution s;
  int a[8] = {1,2,3,4,5,6,7,8};
  vector<int> vec(a, a+3);
  cout << s.missingNumber(vec) << endl;
 
  return 0;
}
