#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution{
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int size = nums.size();
    vector<int> ans(size, -1);
    stack<int> s;
    for (int i = 0; i < size * 2; i++) {
      int num = nums[i % size];
      while (!s.empty() && nums[s.top()] < num) {
	ans[s.top()] = num;
	s.pop();
      }
      if (i < size)
	s.push(i);
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int a[3] = {1,2,1};
  vector<int> vec(a, a+3);
  vector<int> res = s.nextGreaterElements(vec);
  for (int i : res)
    cout << i << " ";
  cout << endl;
  return 0;
}
