#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set(nums1.begin(), nums1.end());
    vector<int> ans;
    for (int i = 0; i < nums2.size(); i++) {
      if (set.count(nums2[i])) {
	ans.push_back(nums2[i]);
	set.erase(nums2[i]);
      } 
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int a[4] = {1,2,2,1};
  int b[2] = {2,2};
  vector<int> vec1(a, a+4);
  vector<int> vec2(b, b+2);
  vector<int> ans = s.intersection(vec1, vec2);
  vector<int>::iterator it = ans.begin();
  while (it != ans.end()) {
    cout << *it << " ";
    ++it;
  }
  cout << endl;
  return 0;
}
