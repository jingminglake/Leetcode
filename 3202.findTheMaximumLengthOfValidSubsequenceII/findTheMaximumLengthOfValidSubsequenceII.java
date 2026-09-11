class Solution {
    public int maximumLength(int[] nums, int k) {
        int res = 0;
        int[][] dp = new int[k][k];
        for (int i = 0; i < nums.length; i++) {
            int x = nums[i] % k;
            for (int y = 0; y < k; y++) {
                dp[y][x] = dp[x][y] + 1;
                res = Math.max(res, dp[y][x]);
            }
        }
        return res;
    }
}
