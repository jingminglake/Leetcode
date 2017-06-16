#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution{
public:
  vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    vector<int> ans;
    stack<int> s;
    unordered_map<int, int> m;
    for (int num : nums) {
      while (!s.empty() && s.top() < num) {
	m.insert(make_pair(s.top(), num));
	s.pop();
      }
      s.push(num);
    }
    unordered_map<int, int>::iterator it;
    for (int num : findNums) {
      it = m.find(num);
      if (it != m.end())
        ans.push_back(it->second);
      else
	ans.push_back(-1);
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int a[3] = {4,1,2};
  int b[4] = {1,3,4,2};
  vector<int> vec1(a, a+3);
  vector<int> vec2(b, b+4);
  vector<int> res = s.nextGreaterElement(vec1, vec2);
  for (int i : res)
    cout << i << " ";
  cout << endl;
  return 0;
}
