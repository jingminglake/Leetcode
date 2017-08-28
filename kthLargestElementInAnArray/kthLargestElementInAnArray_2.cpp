// clang++ kthLargestElementInAnArray_2.cpp -std=c++11

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution{
public:
  int findKthLargest(vector<int> nums, int k) {
    int ans = 0;
    priority_queue<int,vector<int>,greater<int>> q;
    /*for (int num : nums) {
      q.push(num);
    }
    for (int i = 0; i < k; i++) {
      ans = q.top();
      q.pop();
      }
    return ans;*/
    for (int num : nums) {
      if (q.size() < k) {
	q.push(num);
      } else {
	if (q.top() < num) {
	  q.pop();
	  q.push(num);
	}
      }
    }
    return q.top();
  }
};

int main()
{
  Solution s;
  vector<int> vec = {3,2,1,5,6,4}; 
  cout << s.findKthLargest(vec, 2);
  cout << endl;
  return 0;
}
