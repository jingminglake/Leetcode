#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int findShortestSubArray(vector<int>& nums) {
    int res = INT_MAX;
    unordered_map<int, int> m;
    unordered_map<int, pair<int, int> > m2;
    int degree = 0;
    for (int i = 0; i < nums.size(); i++) {
      m[nums[i]]++;
      degree = max(degree, m[nums[i]]);
      if ( m2.count(nums[i]) ) {
	m2[nums[i]].second = i;
      } else {
	m2[nums[i]] = make_pair(i, i);
      }
    }
    for (auto& it : m) {
      if (it.second == degree) {
	res = min(res, m2[it.first].second - m2[it.first].first + 1);
      }
    }
    return res;
  }
};

int main()
{
  Solution s;
  vector<int> ss = {1,2,2,3,1};
  vector<int> ss1 = {1,2,2,3,1,4,2};
  cout << s.findShortestSubArray(ss) << endl;
  cout << s.findShortestSubArray(ss1) << endl;
  return 0;
}
