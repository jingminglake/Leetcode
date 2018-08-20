// clang++ splitArrayIntoConsecutiveSubsequences.cpp -std=c++11

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int> > > m;
        for (int num : nums) {
            if (m.count(num - 1) && !m[num - 1].empty()) {
                int prev_len = m[num - 1].top();
                m[num - 1].pop();
                m[num].push(prev_len + 1);
            } else {
                m[num].push(1);
            }
        }
        for (auto& p : m) {
            if (!p.second.empty() && p.second.top() < 3) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
  Solution s;
  vector<int> nums = {1,2,3,4,4,5};
  cout << s.isPossible(nums);
  cout << endl;
  return 0;
}
