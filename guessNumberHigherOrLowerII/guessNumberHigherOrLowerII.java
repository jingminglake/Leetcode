class Solution {
    public int getMoneyAmount(int n) {
        int[][] dp = new int[n + 1][n + 1];
        return dfs(dp, 1, n);
    }
    
    public int dfs(int[][] dp, int start, int end) {
        if (start == end) return dp[start][end] = 0;
        if (dp[start][end] != 0) return dp[start][end];
        int cur = Integer.MAX_VALUE;
        for (int i = start; i <= end; i++) {
            if (i == start) {
                cur = Math.min(cur, i + dfs(dp, i + 1, end));
            } else if (i == end) {
                cur = Math.min(cur, i + dfs(dp, start, i - 1));
            } else {
                cur = Math.min(cur, i + Math.max(dfs(dp, start, i - 1), dfs(dp, i + 1, end)));
            }
        }
        return dp[start][end] = cur;
    }
}
