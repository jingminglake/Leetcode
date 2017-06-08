#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> map;
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++) {
      unordered_map<int, int>::iterator it = map.find(nums1[i]);
      if (it != map.end())
	it->second++;
      else 
        map.insert(make_pair(nums1[i], 1));
    }
    for (int j = 0; j < nums2.size(); j++) {
      unordered_map<int, int>::iterator it = map.find(nums2[j]);
      if (it != map.end()) {
	if (it->second-- > 0)
	 ans.push_back(nums2[j]);
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
  vector<int> ans = s.intersect(vec1, vec2);
  vector<int>::iterator it = ans.begin();
  while (it != ans.end()) {
    cout << *it << " ";
    ++it;
  }
  cout << endl;
  return 0;
}
