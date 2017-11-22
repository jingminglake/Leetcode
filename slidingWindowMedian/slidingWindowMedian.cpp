// clang++ slidingWindowMedian.cpp -std=c++11

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution{
public:
  vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> res;
    multiset<double> leftS, rightS;
    for (int i = 0; i < nums.size(); i++) {
      if (i >= k) { // if i >= k remove before get
	if (leftS.count(nums[i - k])) {
	  leftS.erase(leftS.find(nums[i - k]));
	} else if (rightS.count(nums[i - k])){
	  rightS.erase(rightS.find(nums[i - k]));
	}
      }
      if (!leftS.empty() && (leftS.size() - 2 == rightS.size())) {
	rightS.insert(*leftS.rbegin());
	leftS.erase(--leftS.end());
      }
      if (leftS.size() <= rightS.size()) {
	if (leftS.empty() || nums[i] <= *leftS.rbegin())
	  leftS.insert(nums[i]);
	else {
	  rightS.insert(nums[i]);
	  leftS.insert(*rightS.begin());
	  rightS.erase(rightS.begin());
	}
      } else {
	if (rightS.empty() || nums[i] >= *rightS.begin())
	  rightS.insert(nums[i]);
	else {
	  leftS.insert(nums[i]);
	  rightS.insert(*leftS.rbegin());
	  leftS.erase(--leftS.end());
	}
      }
      if (i >= k - 1) {
	if (k % 2)
	  res.push_back(*leftS.rbegin());
	else
	  res.push_back((*leftS.rbegin() + *rightS.begin()) / 2.0);
      }
    }
    return res;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1,3,-1,-3,5,3,6,7};
  vector<double> vec = s.medianSlidingWindow(nums, 3);
  for (double d : vec)
    cout << d << " ";
  cout << endl;
  return 0;
}
