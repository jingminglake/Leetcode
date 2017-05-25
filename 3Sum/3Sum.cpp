#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > ans;
    if(nums.size() < 3)
      return ans;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++) {
      int target = -nums[i];
      if(target < 0)
	break;
      int front = i + 1;
      int rear = nums.size() - 1;
      while (front < rear) {
	int sum = nums[front] + nums[rear];
	if(sum < target)
	  front++;
	else if(sum > target)
	  rear--;
	else {
	  vector<int> temp(3, 0);
	  temp[0] = nums[i];
	  temp[1] = nums[front];
	  temp[2] = nums[rear];
	  ans.push_back(temp);
	  while(front < rear && nums[front] == temp[1])
	    front++;
	  while(front < rear && nums[front] == temp[2])
	    rear--;
	}
      }//while
      while(i + 1 < nums.size() && nums[i + 1] == nums[i])
	i++;
    }//for

    return ans;
  }
};
int main()
{
  Solution s;
  int a[6] = {-1, 0, 1, 2, -1, -4};
  vector<int> nums(a, a+6);
  vector<vector<int> > vec = s.threeSum(nums);
  vector<vector<int> >::iterator it = vec.begin();
  while(it != vec.end()) {
    vector<int>::iterator it2 = (*it).begin();
    while(it2 != (*it).end()) {
      cout << *it2 << " ";
      ++it2;
    }
    cout << endl;
    ++it;
  }
  return 0;
}
