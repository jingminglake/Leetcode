#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
  vector<string> findRelativeRanks(vector<int>& nums) {
    int size =  nums.size();
    vector<string> ans(size, "");
    map<int, int> m;
    for (int i = 0; i < size; i++) {
      m.insert(make_pair(nums[i],i));
    }
    map<int, int>::reverse_iterator rit = m.rbegin();
    int i = 1;
    while (rit != m.rend()) {
      //cout << rit->first << " " << rit->second << endl;
      if (i == 1)
	ans[rit->second] = "Gold Medal";
      else if (i == 2)
	ans[rit->second] = "Silver Medal";
      else if (i == 3)
	ans[rit->second] = "Bronze Medal";
      else
	ans[rit->second] = to_string(i);
      ++i;
      ++rit;
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int a[7] = {5,4,3,2,1,6,7};
  vector<int> v(a, a+7);
  vector<string> vec = s.findRelativeRanks(v);
  for (string str : vec)
    cout << str << " ";
  cout << endl;
  return 0;
}
