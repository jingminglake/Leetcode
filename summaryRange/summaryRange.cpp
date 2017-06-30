#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  vector<string> summaryRanges(vector<int>& nums) {
    int size = nums.size();
    vector<string> ans;
    if (size < 1)
      return ans;
    string temp = "";
    temp += to_string(nums[0]);
    int count = 1;
    for (int i = 1; i < size; i++) {
      if (nums[i] != nums[i-1] + 1) {
	if (count >= 2) {
	  temp += "->";
	  temp += to_string(nums[i-1]);
	}
	ans.push_back(temp);
	temp = to_string(nums[i]);
	count = 1;
      } else
	count++;
       if (i == size - 1 && count >= 2) {
	  temp += "->";
	  temp += to_string(nums[i]);
	  ans.push_back(temp);
	}
    }
    if (temp == to_string(nums[size-1]))
      ans.push_back(temp);
    return ans;
  }
};

int main()
{
  Solution s;
  int a[4] = {0,1,5,7};
  vector<int> vec(a, a+4);
  vector<string> res = s.summaryRanges(vec);
  for (string s : res) {
    cout << s << " ";
  }
  cout << endl;
  return 0;
}
