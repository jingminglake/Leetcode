class Solution {
    public double largestSumOfAverages(int[] nums, int k) {
        double[][] dp = new double[nums.length + 1][k + 1];
        dp[0][0] = 0.0;
        double sum0I = 0.0;
        for (int i = 1; i <= nums.length; i++) {
            sum0I += nums[i - 1];
            dp[i][1] = sum0I / i;
        }
        for (int j = 2; j <= k; j++) {
            for (int i = 1; i <= nums.length; i++) {           
                double sumXI = 0.0;
                for (int x = i - 1; x >= 0; x--) {
                    sumXI += nums[x];
                    dp[i][j] = Math.max(dp[i][j], dp[x][j - 1] + sumXI / (i - x));
                }
            }
        }
        return dp[nums.length][k];
    }
}
