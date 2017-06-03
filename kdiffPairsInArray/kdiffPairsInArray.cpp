#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  int findPairs(vector<int>& nums, int k) {
    int ans = 0;
    if (k < 0)
      return ans;
    int size = nums.size();
    if (size < 2)
      return ans;
    unordered_map<int, int> map;
    map.insert(make_pair(nums[0], 1)); 
    unordered_map<int, int>::iterator it;
    for (int i = 1; i < nums.size(); i++) {
      it = map.find(nums[i]);
      if (it != map.end()) {//find
	it->second++;
	continue;
      }
      map.insert(make_pair(nums[i], 1));
      if (k != 0) {
	it = map.find(nums[i] + k);
	if (it != map.end()) //find
	  ans++;
	it = map.find(nums[i] - k);
	if (it != map.end()) //find
	  ans++;
      }	
    }
    if (k == 0) {
      ans = 0;
      it = map.begin();
      while (it != map.end()) {
	if (it->second > 1)
	  ans++;
	++it;
      }
    }
      
    return ans;
  }
};

int main()
{
  Solution s;
  int a[5] = {1,3,1,5,4};
  vector<int> vec(a, a+5);
  cout << s.findPairs(vec, 0);
  cout << endl;
  return 0;
}
