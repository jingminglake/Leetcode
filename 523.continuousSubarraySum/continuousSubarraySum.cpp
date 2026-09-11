// clang++ continuousSubarraySum.cpp -std=c++11

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return false;
        vector<int> preSum(nums.size(), 0); 
        preSum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            preSum[i] = preSum[i - 1] + nums[i];
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < preSum.size(); i++) {
            int key = preSum[i];
            if (k)
                key = preSum[i] % k;
            if (m.count(key)) {
                if (i - m[key] > 1)
                    return true;
            } else {
                m[key] = i;
            }
        }
        return false;
    }
};

int main()
{
  Solution s;
  vector<int> nums = {23,2,6,4,7};
  cout << s.checkSubarraySum(nums, 6) << endl;
  return 0;
}
