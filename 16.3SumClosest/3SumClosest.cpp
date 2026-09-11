#include <iostream>
#include <vector>
#include <cstdlib>
#include <numeric>
using namespace std;

class Solution{
public:
  int threeSumClosest(vector<int>& nums, int target) {
    if(nums.size() <= 3)
      return accumulate(nums.begin(), nums.end(), 0);
    int ans = nums[0] + nums[1] + nums[2];
    sort(nums.begin(), nums.end());
    int len = nums.size();
    for(int i = 0; i < len; i++){
      int front = i + 1;
      int rear = len - 1;
      while(front < rear){
	int val = nums[i] + nums[front] + nums[rear];
	if(abs(val - target) < abs(ans - target))
	  ans = val;
	val < target ? front++ : rear--;
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int a[4] = {-1, 2, 1, -4};
  vector<int> vec(a, a+4);
  cout << s.threeSumClosest(vec, 1) << endl;
  return 0;
}
