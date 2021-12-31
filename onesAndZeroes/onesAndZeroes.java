class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int[][][] dp = new int[strs.length + 1][m + 1][n + 1];
        for (int k = 1; k <= strs.length; k++) {
            int[] nums = getNums(strs[k - 1]);
            for (int i = 0; i <= m; i++) {
                for (int j = 0; j <= n; j++) {
                    if (i >= nums[0] && j >= nums[1]) {
                        dp[k][i][j] = Math.max(dp[k - 1][i][j], dp[k - 1][i - nums[0]][j - nums[1]] + 1);
                    } else {
                        dp[k][i][j] = dp[k - 1][i][j];
                    }
                }
            }
        }
        return dp[strs.length][m][n];
    }
    
    public int[] getNums(String str) {
        int[] nums = new int[2];
        for (char c : str.toCharArray()) {
            if (c == '0') nums[0]++;
            else if (c == '1') nums[1]++;
        }
        return nums;
    }
}
