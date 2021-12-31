class Solution {
    public double soupServings(int n) {
        if (n > 4800) return 1.0;
        n = (n + 24) / 25;
        double[][] dp = new double[n + 1][n + 1];
        dp[0][0] = 0.5;
        for (int j = 1; j <= n; j++) dp[0][j] = 1;
        int[][] serve = {{4, 0}, {3, 1}, {2, 2}, {1, 3}};
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int[] s : serve) {
                    int prevI = i >= s[0] ? i - s[0] : 0;
                    int prevJ = j >= s[1] ? j - s[1] : 0;
                    dp[i][j] += 0.25 * dp[prevI][prevJ];
                }
            }
        }
        return dp[n][n];
    }
}
