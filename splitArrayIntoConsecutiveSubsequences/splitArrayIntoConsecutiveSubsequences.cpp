// clang++ splitArrayIntoConsecutiveSubsequences.cpp -std=c++11

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution{
public:
  bool isPossible(vector<int>& nums) {
    unordered_map<int, priority_queue<int, vector<int>, greater<int> > > m;
    for (int num : nums) {
      if (!m[num - 1].empty()) {
	m[num].push(m[num - 1].top() + 1);
	m[num - 1].pop();
      }	else {
	m[num].push(1);
      }
    }//for
    for (auto& n : m) {
      priority_queue<int, vector<int>, greater<int> >& pq = n.second;
      while (pq.size()) {
	int len = pq.top();
	pq.pop();
	if (len < 3)
	  return false;
      }
    }
    return true;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1,2,3,4,4,5};
  cout << s.isPossible(nums);
  cout << endl;
  return 0;
}
