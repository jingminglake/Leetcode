#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.size() == 0)
            return 0;
        int res = 0;
        int target = 0;
        dfs(S, res, nums, 0, 0);
        return res;
    }
    void dfs(int& S, int& res, vector<int>& nums, int start, int target) {
        if (start == nums.size()) {
            if (target == S)
                res++;
            return;
        }
        dfs(S, res, nums, start + 1, target - nums[start]);
        dfs(S, res, nums, start + 1, target + nums[start]);
    }
};

int main()
{
  Solution s;
  vector<int> vec(5, 1);
  cout << s.findTargetSumWays(vec, 3);
  cout << endl;
  return 0;
}
