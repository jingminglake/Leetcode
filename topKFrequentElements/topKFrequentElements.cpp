#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution{
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ans;
    int size = nums.size();
    if (size < 1)
      return ans;
    unordered_map<int, int> m;
    for (int num : nums) {
      m[num]++;
    }
    vector<vector<int> > bucket(size+1, vector<int>(0));
    unordered_map<int, int>::iterator it = m.begin();
    while (it != m.end()) {
      bucket[it->second].push_back(it->first);
      ++it;
    }
    for (int i = size; i > 0 && ans.size() < k; i--) {
      for (int j = 0; j < bucket[i].size(); j++)
	ans.push_back(bucket[i][j]);
    }
    return ans;
  }
};

int main()
{
  Solution s;
  int a[6] = {1, 1, 1, 2, 2, 3};
  vector<int> vec(a, a+6);
  vector<int> res = s.topKFrequent(vec, 2);
  for (int i : res)
    cout << i << " ";
  cout << endl;
  return 0;
}
