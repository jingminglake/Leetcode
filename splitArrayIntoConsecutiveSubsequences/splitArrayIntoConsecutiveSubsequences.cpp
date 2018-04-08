// clang++ splitArrayIntoConsecutiveSubsequences.cpp -std=c++11

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, std::greater<int> > > tailMap;
        for (int num : nums) {
            if (!tailMap[num - 1].empty()) {
                tailMap[num].push(tailMap[num - 1].top() + 1);
                tailMap[num - 1].pop();
            } else {
                tailMap[num].push(1);
            }
        }
        for (auto& p : tailMap) {
            if (!p.second.empty() && p.second.top() < 3)
                return false;
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
