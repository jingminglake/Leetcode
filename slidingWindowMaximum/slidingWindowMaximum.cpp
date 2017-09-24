// clang++ slidingWindowMaximum.cpp -std=c++11

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;


class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int size = nums.size();
    vector<int> window;
    deque<int> dq;
    for (int i = 0; i < size; i++) {
      while (!dq.empty() && dq.front() < i - k + 1) // i - k + 1 is the start point of window
	dq.pop_front();
      while (!dq.empty() && nums[dq.back()] < nums[i])
	dq.pop_back();
      dq.push_back(i);
      if (i >= k - 1) // from k + 1, we start count the max
	window.push_back(nums[dq.front()]);
    }
    return window;
  }
};

int main()
{
  Solution s;
  vector<int>  nums = {1,3,-1,-3,5,3,6,7};
  vector<int> res = s.maxSlidingWindow(nums, 3);
  for (int i : res)
    cout << i << " ";
  cout << endl;
  return 0;
}
