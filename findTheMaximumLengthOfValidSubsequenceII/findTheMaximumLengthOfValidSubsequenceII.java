class Solution {
    public int maximumLength(int[] nums, int k) {
        int res = 0;
        int[][] dp = new int[k][k];
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < k; j++) {
                dp[nums[i] % k][j] = dp[j][nums[i] % k] + 1;
                res = Math.max(res, dp[nums[i] % k][j]);
            }
        }
        return res;
    }
}