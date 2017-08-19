#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  string largestNumber(vector<int>& nums) {
    string ans;
    if (nums.size() == 0)
      return ans;
    vector<string> vec;
    for (int num : nums)
      vec.push_back(to_string(num));
    sort(vec.begin(), vec.end(), [](string &s1, string &s2) {return s1+s2 > s2+s1;});
    for (string &s : vec) {
      ans += s;
    }
    while (ans.length() > 1 && ans[0] == '0') {
      ans.erase(0,1);
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int a[5] = {3,30,34,5,9};
  vector<int> nums(a, a+5);
  cout << s.largestNumber(nums) << endl;
  return 0;
}
