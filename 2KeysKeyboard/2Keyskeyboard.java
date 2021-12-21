class Solution {
    public int minSteps(int n) {
        if (n < 2) return 0;
        int[] dp = new int[n + 1];
        for (int i = 0; i <= n; i++) dp[i] = Integer.MAX_VALUE;
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            for (int j = i / 2; j >= 1; j--) {
                if (i % j == 0) {
                    dp[i] = Math.min (dp[i], dp[j] + i / j);
                    break;
                }
            }
        }
        return dp[n];
    }
}
