#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int ans = 0;
    int size = nums.size();
    if (size < 0)
      return ans;
    int temp = 0;
    for (int i = 0; i < size; i++) {
      if (nums[i] == 1) {
	if (++temp > ans)
	  ans = temp;
      }
      else if (nums[i] == 0) {
	temp = 0;
      }
	
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int a[8] = {1,1,0,1,1,1,0,1};
  vector<int> vec(a, a+8);
  cout << s.findMaxConsecutiveOnes(vec) << endl;
 
  return 0;
}
