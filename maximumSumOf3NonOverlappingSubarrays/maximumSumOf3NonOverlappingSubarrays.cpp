#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> res;
        if (k < 0 || nums.size() < 3*k)
            return res;
        vector<int> preSum(nums.size(), 0);
        preSum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            preSum[i] = preSum[i - 1] + nums[i];
        vector<int> posLeft(nums.size(), k - 1);
        int leftRangeSum = preSum[k - 1];
        for (int i = k; i < nums.size(); i++) {
            if (preSum[i] - preSum[i - k + 1] + nums[i - k + 1] > leftRangeSum) {
                posLeft[i] = i;
                leftRangeSum = preSum[i] - preSum[i - k + 1] + nums[i - k + 1];
            }
            else
                posLeft[i] = posLeft[i - 1];
        }
        vector<int> posRight(nums.size(), nums.size() - k);
        int rightRangeSum = preSum[nums.size() - 1] - preSum[nums.size() - k] + nums[nums.size() - k];
        for (int i = nums.size() - k - 1; i >= 0; i--) {
            if (preSum[i + k - 1] - preSum[i] + nums[i] > rightRangeSum) {
                posRight[i] = i;
                rightRangeSum = preSum[i + k - 1] - preSum[i] + nums[i];
            }
            else
                posRight[i] = posRight[i + 1];
        }
        int maxSum = 0;
        for (int i = k; i <= nums.size() - 2*k; i++) {
            int l = posLeft[i - 1], r = posRight[i + k];
            int total = (preSum[l] - preSum[l - k + 1] + nums[l - k + 1]) + (preSum[i + k - 1] - preSum[i] + nums[i]) + (preSum[r + k - 1] - preSum[r] + nums[r]);
            if (total > maxSum) {
                maxSum = total;
                res = {l - k + 1, i, r};
            }
        }
        return res;
    }
};

int main()
{
  Solution s;
  vector<int> vec = {1, 2, 1, 3, 6, 7, 5, 1};
  for (int i : s.maxSumOfThreeSubarrays(vec, 2))
    cout << i << " "; 
  cout << endl;
  return 0;
}
