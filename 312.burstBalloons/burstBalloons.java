class Solution {
    public int maxCoins(int[] nums) {
        int[][] dp = new int[nums.length][nums.length];
        for (int[] arr : dp) { Arrays.fill(arr, -1); }
        return dfs(nums, dp, 0, nums.length - 1);
    }
    
    public int dfs(int[] nums, int[][] dp, int i, int j) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int res = 0;
        for (int k = i; k <= j; k++) {
            int boundLeft = i - 1 >= 0 ? nums[i - 1] : 1;
            int boundRight = j + 1 < nums.length ? nums[j + 1] : 1;
            res = Math.max(res, dfs(nums, dp, i, k - 1) + boundLeft * nums[k] * boundRight + dfs(nums, dp, k + 1, j));
        }
        return dp[i][j] = res;
    }
}
