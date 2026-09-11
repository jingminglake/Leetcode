#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
  int findHS(vector<int>& nums) {
    int ans = 0;
    int size = nums.size();
    map<int, int> m;
    for (int i = 0; i < size; i++) {
      map<int, int>::iterator it = m.find(nums[i]);
      if (it != m.end())
	it->second++;
      else 
        m.insert(make_pair(nums[i], 1));
    }
    map<int, int>::iterator it = m.begin();
    while (it != m.end()) {
      map<int, int>::iterator it2 = m.find(it->first + 1);
      if (it2 != m.end())	
	ans = max(ans, it2->second + it->second);
      ++it;
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int a[8] = {1,3,2,2,5,2,3,7};
  vector<int> vec(a, a+8);
  cout << s.findHS(vec);
  cout << endl;
  return 0;
}
