class Solution {
    public int findLengthOfLCIS(int[] nums) {
        int res = 1;
        int dp = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[i - 1]) dp++;
            else dp = 1;
            res = Math.max(res, dp);
        }
        return res;
    }
}
