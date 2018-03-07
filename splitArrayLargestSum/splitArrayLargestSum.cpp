#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        if (nums.size() == 0)
            return 0;
        long long left = 0, right = 0;
        for (int num : nums) {
            left = max ((int)left, num);
            right += num;
        }
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            //cout << left << " " << mid << " " <<  right << endl;
            if (canSplit(nums, m, mid))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
    bool canSplit(vector<int>& nums, int m, long long sum) {
        long long curSum = 0;
        int count = 0;
        //cout << sum << endl;
        for (int i = 0; i < nums.size(); i++) {
            curSum += nums[i];
            if (curSum > sum) {
                curSum = nums[i];
                count++;
                if (count >= m) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
  Solution s;
  vector<int> nums = {7,2,5,10,8};
  cout << s.splitArray(nums, 2);
  cout << endl;
  return 0;
}
