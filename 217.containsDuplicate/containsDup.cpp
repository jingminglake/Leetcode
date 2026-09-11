#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  bool contiansDuplicate(vector<int>& nums) {
    int size = nums.size();
    if (size < 2)
      return false;
    unordered_map<int, int> map;
    map.insert(make_pair(nums[0], 0));
    unordered_map<int, int>::iterator it;
    for (int i = 1; i < size; i++) {
      it = map.find(nums[i]);
      if (it != map.end())
	return true;
      else
	map.insert(make_pair(nums[i], i));
    }
    return false;
  }
};

int main()
{
  Solution s;
  int a[8] = {4,3,2,7,8,4,5,1};
  vector<int> vec(a, a+8);
  cout << s.contiansDuplicate(vec) << endl;
 
  return 0;
}
