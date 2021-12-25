class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        int m = dungeon.length, n = dungeon[0].length;
        int[][] dp = new int[m][n];
        dp[m - 1][n - 1] = -dungeon[m - 1][n - 1] + 1;
        if (dp[m - 1][n - 1] <= 0) dp[m - 1][n - 1] = 1;
        for (int i = m - 2; i >= 0; i--) {
            dp[i][n - 1] = dp[i + 1][n - 1] - dungeon[i][n - 1];
            if (dp[i][n - 1] <= 0) dp[i][n - 1] = 1;
        }
        for (int j = n - 2; j >= 0; j--) {
            dp[m - 1][j] = dp[m - 1][j + 1] - dungeon[m - 1][j];
            if (dp[m - 1][j] <= 0) dp[m - 1][j] = 1;
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                dp[i][j] = Math.min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                if (dp[i][j]  <= 0) dp[i][j] = 1;
            }
        }
        return dp[0][0];
    }
}
