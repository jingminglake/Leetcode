#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int size = nums.size();
    vector<int> ans(size, 0);
    /*int accum = 1;
    for (int i = 0; i < size; i++) {
      accum *= nums[i];
    }
    for (int i = 0; i < size; i++) {
      if (nums[i])
        ans[i] = accum/nums[i];
      else {
	int temp = 1;
	for (int j = 0; j < size; j++)
	  if (j != i)
	    temp *= nums[j];
	ans[i] = temp;
      }
      }*/
    ans[0] = 1;
    for (int i = 1; i < size; i++) {
       ans[i] = ans[i-1] * nums[i-1];
    }
    int accumRight = 1;
    for (int i = size - 1; i >= 0; i--) {
	ans[i] *= accumRight;
	accumRight *= nums[i];
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int a[4] = {1,0,0,1};
  vector<int> vec(a, a+2);
  vector<int> res = s.productExceptSelf(vec);
  for (int i : res) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
