class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        int m = dungeon.length, n = dungeon[0].length;
        int[][] dp = new int[m][n];
        if (dungeon[m - 1][n - 1] >= 0) dp[m - 1][n - 1] = 1;
        else dp[m - 1][n - 1] = 1 - dungeon[m - 1][n - 1];

        for (int i = m - 2; i >= 0; i--) {
            if (dungeon[i][n - 1] < dp[i + 1][n - 1])
                dp[i][n - 1] = dp[i + 1][n - 1] - dungeon[i][n - 1];
            else
                dp[i][n - 1] = 1;
        }
        for (int j = n - 2; j >= 0; j--) {
            if (dungeon[m - 1][j] < dp[m - 1][j + 1])
                dp[m - 1][j] = dp[m - 1][j + 1] - dungeon[m - 1][j];
            else
                dp[m - 1][j] = 1;
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                int dp_down = 1;
                if (dungeon[i][j] < dp[i + 1][j])
                    dp_down = dp[i + 1][j] - dungeon[i][j];
                else
                    dp_down = 1;

                int dp_right = 1;
                if (dungeon[i][j] < dp[i][j + 1])
                    dp_right = dp[i][j + 1] - dungeon[i][j];
                else
                    dp_right = 1;

                dp[i][j] = Math.min(dp_down, dp_right);
            }
        }
        return dp[0][0];
    }
}
