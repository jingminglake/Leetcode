#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  vector<int> majorityElement(vector<int>& nums) {
    vector<int> ans;
    int candidate1 = 0, candidate2 = 0;
    int count1 = 0, count2 = 0;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      if (candidate1 == nums[i]) {
	count1++;
      } else if (candidate2 == nums[i]) {
	count2++;
      } else if (count1 == 0) {
	candidate1 = nums[i];
	count1 = 1;
      } else if (count2 == 0) {
	candidate2 = nums[i];
	count2 = 1;
      } else {
	count1--;
	count2--;
      }
    }
    count1 = 0;
    count2 = 0;
    for (int num : nums) {
      if (candidate1 == num)
	count1++;
      else if (candidate2 == num)
	count2++;
    }
    cout << count1 << " " << count2 << endl;
    if (count1 > size/3)
      ans.push_back(candidate1);
    if (count2 > size/3)
      ans.push_back(candidate2);
    return ans;
  }
};

int main()
{
  Solution s;
  int a[5] = {8,8,7,7,7};
  vector<int> vec(a, a+5);
  vector<int> res = s.majorityElement(vec);
  for (int num : res)
    cout << num << " ";
  cout << endl;
  return 0;
}
