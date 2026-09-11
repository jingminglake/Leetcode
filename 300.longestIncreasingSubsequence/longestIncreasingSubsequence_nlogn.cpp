#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> tail;
        for (int i = 0; i < n; i++) {
            int index = find_last_less_than(tail, nums[i]);
            if (index == tail.size())
                tail.push_back(nums[i]);
            else
                tail[index] = nums[i];
        }
        return tail.size();
    }
    int find_last_less_than(vector<int>& tail, int target) {
        int left = 0, right = tail.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (tail[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << s.lengthOfLIS(nums) << endl;
    return 0;
}
