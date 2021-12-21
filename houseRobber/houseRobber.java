class Solution {
    public int rob(int[] nums) {
        if (nums.length < 2) return nums[0];
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        dp[1] = nums[1];
        if (nums.length == 2) return Math.max(dp[0], dp[1]);
        dp[2] = nums[0] + nums[2];
        int res = Math.max(dp[1], dp[2]);
        for (int i = 3; i < dp.length; i++) {
            dp[i] = Math.max(dp[i - 2], dp[i - 3]) + nums[i];
            res = Math.max(res, dp[i]);
        }
        return res;
    }
}
