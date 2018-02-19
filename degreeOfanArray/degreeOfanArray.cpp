#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int res = INT_MAX;
        unordered_map<int, int> m; // num -> freq
        unordered_map<int, pair<int, int> > m2; // num -> (firstLoc, LastLoc)
        int degree = 0;
        for (int i = 0; i < nums.size(); i++) {
            degree = max (degree, ++m[nums[i]]);
            if (m2.count(nums[i]) == 0)
                m2[nums[i]] = make_pair(i, i);
            else
                m2[nums[i]].second = i;
        }
        for (int num : nums) {
            if (m[num] == degree) {
                res = min (res, m2[num].second - m2[num].first + 1);
            }
        }
        return res;
    }
};

int main()
{
  Solution s;
  vector<int> ss = {1,2,2,3,1};
  vector<int> ss1 = {1,2,2,3,1,4,2};
  cout << s.findShortestSubArray(ss) << endl;
  cout << s.findShortestSubArray(ss1) << endl;
  return 0;
}
