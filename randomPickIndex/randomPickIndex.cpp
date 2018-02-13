class Solution {
public:
    Solution(vector<int> nums) {
        num = nums;
    }
    
    int pick(int target) {
        int res = -1, count = 0;
        for (int i = 0; i < num.size(); i++) {
            if (num[i] == target) {
                count++;
                if (rand() % count == 0)
                    res = i;
            }
        }
        return res;
    }
    vector<int> num;
};
