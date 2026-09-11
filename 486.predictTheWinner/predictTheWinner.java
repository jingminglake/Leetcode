class Solution {
    public boolean PredictTheWinner(int[] nums) {
        int[][] dp = new int[nums.length][nums.length];
        for (int[] row : dp) Arrays.fill(row, -1);
        long sum = 0;
        for (int num : nums) sum += num;
        return dfs(dp, nums, 0, nums.length - 1) * 2 >= sum;
    }
    
    public int dfs(int[][] dp, int[] nums, int i, int j) {
        if (i > j) return 0;
        else if (i == j) return nums[i];
        if (dp[i][j] != -1) return dp[i][j];
        int start = nums[i] + Math.min(dfs(dp, nums, i + 2, j), dfs(dp, nums, i + 1, j - 1));
        int end = nums[j] + Math.min(dfs(dp, nums, i + 1, j - 1), dfs(dp, nums, i, j - 2));
        return dp[i][j] = Math.max(start, end);
    }
}
