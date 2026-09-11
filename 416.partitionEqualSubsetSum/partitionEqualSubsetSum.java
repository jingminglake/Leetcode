class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        boolean dp[][] = new boolean[nums.length + 1][target + 1];
        dp[0][0] = true;
        for (int i = 1; i <= nums.length; i++) {
            for (int j = 0; j <= target; j++) {
                if (dp[i - 1][j]) { 
                    dp[i][j] = true;
                } else if (j - nums[i - 1] >= 0) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[nums.length][target];
    }
}
