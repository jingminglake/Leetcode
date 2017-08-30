// clang++ findKPairsWithSmallestSums.cpp -std=c++11

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Compare {
public:
  bool operator()(const tuple<int, int, int>& p1, const tuple<int, int, int>& p2) {
    return get<0>(p1) + get<1>(p1) > get<0>(p2) + get<1>(p2);
  }
};

class Solution{
public:
  vector<pair<int, int> > kthSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, Compare > pq;
    vector<pair<int, int> > ans;
    int nums1Size = nums1.size();
    int nums2Size = nums2.size();
    if (nums1Size == 0 || nums2Size == 0 || k == 0)
      return ans;
    for (int i = 0; i < nums1Size && i < k; i++) {
      pq.push(make_tuple(nums1[i], nums2[0], 0));
    }
    while (k-- > 0 && !pq.empty()) {
      tuple<int, int, int> t = pq.top();
      pq.pop();
      ans.push_back(make_pair(get<0>(t), get<1>(t)));
      if (get<2>(t) == nums2Size - 1)
	continue;
      pq.push(make_tuple(get<0>(t), nums2[get<2>(t) + 1], get<2>(t) + 1));
    }
    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> nums1 = {1,1,2};
  vector<int> nums2 = {1,2,3};
  vector<vector<int> > matrix;
  matrix.push_back(nums1);
  matrix.push_back(nums2);
  vector<pair<int,int> > res = s.kthSmallestPairs(nums1, nums2, 3);
  for (pair<int, int>& p : res)
    cout << "(" << p.first << ", " << p.second << ")";
  cout << endl;
  return 0;
}
