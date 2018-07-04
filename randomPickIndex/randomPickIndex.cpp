class Solution {
public:
    Solution(vector<int> nums) {
        nums_ = nums;
        srand(time(0));
    }
    
    int pick(int target) {
        int res = -1, count = 0;
        for (int i = 0; i < nums_.size(); i++) {
            if (nums_[i] == target) {
                count++;
                if (rand() % count == 0)
                    res = i;
            }
        }
        return res;
    }
    vector<int> nums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
