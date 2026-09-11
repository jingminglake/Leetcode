#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

class Solution{
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    /* int size = nums.size();
     for (int i = 0; i < size; i++) {
       for (int j = i + 1; j < (i + k + 1 > size ? size : i + k + 1); j++) {
         if (nums[i] == nums[j])
	   return true;
       }
     }
     return false;*/
    int ans = false;
    int size = nums.size();
    if (size <= 1)
      return ans;
    unordered_map<int, int> map;
    map.insert(make_pair(nums[0], 0));
    unordered_map<int, int>::iterator it;
    for (int i = 1; i < size; i++) {
      it = map.find(nums[i]);
      if (it != map.end()) { //find!
	if (i - it->second <= k) {
	  ans = true;
	  break;
	} else {
	  it->second = i;
	}
      } else { // not find!
	map.insert(make_pair(nums[i], i));
      }
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int a[7] = {1, 0, 1, 1, 4, 5, 0};
  vector<int> vec(a, a+4);
  cout << s.containsNearbyDuplicate(vec, 1) << endl;
  return 0;
}
