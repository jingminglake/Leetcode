class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum < target) return 0;
        int p = target + sum;
        if (p < 0 || p % 2 != 0) return 0;
        p = p / 2;
        
        int[][] dp = new int[nums.length + 1][p + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= nums.length; i++) {
            for (int j = 0; j <= p; j++) {
                dp[i][j] += dp[i - 1][j];
                if (j >= nums[i - 1]) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[nums.length][p];
    }
}
