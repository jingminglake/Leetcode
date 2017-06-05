#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  int majorityElement(vector<int>& nums) {
    unordered_map<int, int> map;
    int size = nums.size();
    int ans = 0;
    unordered_map<int, int>::iterator it;
    for (int i = 0; i < size; i++) {
      it = map.find(nums[i]);
      if (it != map.end()) {
	it->second++;
      }
      else
	map.insert(make_pair(nums[i],0));
    }
    it = map.begin();
    while (it != map.end()) {
      if (it->second >= size/2) {
	ans = it->first;
	break;
      }
      ++it;
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int a[7] = {2,6,4,8,10,9,15};
  vector<int> vec(a, a+7);
  cout << s.majorityElement(vec) << endl;
 
  return 0;
}
