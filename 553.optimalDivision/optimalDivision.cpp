#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  string optimalDivision(vector<int>& nums) {
    string ans;
    int size = nums.size();
    if (size == 0)
      return ans;
    ans = to_string(nums[0]);
    if (size == 1)
      return ans;
    if (size == 2)
      return ans + "/" + to_string(nums[1]);
    ans += "/(" + to_string(nums[1]);
    for (int i = 2; i < nums.size(); i++)
      ans += "/" + to_string(nums[i]);
    ans += ")";
    return ans;
  }
};

int main()
{
  Solution s;
  int a[4] = {1000, 100, 10, 2};
  vector<int> vec(a, a+4);
  cout << s.optimalDivision(vec);
  cout << endl;
  return 0;
}
