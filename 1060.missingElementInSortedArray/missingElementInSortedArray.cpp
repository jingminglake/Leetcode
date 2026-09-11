class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int i = 0;
        while (i < nums.size()) {
            if (i + 1 < nums.size() && nums[i + 1] == nums[i]) {
                i++;
                continue;
            } else {
                if (i + 1 == nums.size()) {
                    return nums.back() + k;
                } else {
                    int delta = nums[i + 1] - nums[i] - 1;
                    if (delta < k)
                        k -= delta;
                    else
                        return nums[i] + k;
                }
                i++;
            }
        }
        return -1;
    }
};
