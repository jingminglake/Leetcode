#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      map<int, int> m;
      for (int i = 0; i < nums.size(); i++)
      {
	int complement = target - nums[i];
	if (m.find(complement) != m.end())
	{
	  vector<int> v;
	  v.push_back(m.find(complement)->second);
	  v.push_back(i);
	  return v;
	}
	m.insert(pair<int, int>(nums[i], i));
      }
      throw (string("not found!"));
    }
};
int main(void)
{
  //std::cout << "Hello World" << std::endl;
  Solution s;
  vector<int> nums;
  nums.push_back(3);
  nums.push_back(2);
  nums.push_back(4);
  nums.push_back(4);
  nums.push_back(4);
  int target = 8;
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
