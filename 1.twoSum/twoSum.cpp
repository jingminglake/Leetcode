#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      for (int i = 0; i < nums.size(); i++)
	for (int j = i + 1; j < nums.size(); j++)
	{
	  if (nums[i] + nums[j] == target)
	  {
	    vector<int> v;
	    v.push_back(i);
	    v.push_back(j);
	    return v;
	  }
	}
      throw (string("not found!"));
    }
};
int main(void)
{
  Solution s;
  vector<int> nums;
  nums.push_back(3);
  nums.push_back(2);
  nums.push_back(4);
  //  nums.push_back(15);
  int target = 6;
  try{
   vector<int> result = s.twoSum(nums, target);
   vector<int>::const_iterator ptr = result.begin();
   while (ptr != result.end())
     {
       cout << *ptr << endl;
       ++ptr;
     }
  }
  catch(const string &msg)
  {
    cout << msg << endl;
  }
  return 0;
}
