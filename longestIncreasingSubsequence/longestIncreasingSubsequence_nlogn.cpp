#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        if (nums.size() == 0)
            return res;
        vector<int> tail;
        for (int i = 0; i < nums.size(); i++) {
            int left = 0, right = tail.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (tail[mid] < nums[i])
                    left = mid + 1;
                else
                    right = mid;
            }
            if (right >= tail.size())
                tail.push_back(nums[i]);
            else
                tail[right] = nums[i];
        }
        return tail.size();
    }
};

int main()
{
  Solution s;
  vector<int> nums = {10,9,2,5,3,7,101,18};
  cout << s.lengthOfLIS(nums) << endl;
  return 0;
}
