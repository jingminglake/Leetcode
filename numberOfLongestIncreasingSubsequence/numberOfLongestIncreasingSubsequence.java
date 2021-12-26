class Solution {
    public int findNumberOfLIS(int[] nums) {
        int[][] dp = new int[nums.length][2]; // 0 -> longest len, 1 -> path number
        dp[0][0] = dp[0][1] = 1;
        int longestLen = 1;
        for (int i = 1; i < nums.length; i++) {
            dp[i][0] = dp[i][1] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[i][0] < dp[j][0] + 1) {
                        dp[i][0] = dp[j][0] + 1;
                        dp[i][1] = dp[j][1];
                    } else if (dp[i][0] == dp[j][0] + 1) {
                        dp[i][1] += dp[j][1];
                    }
                }
            }
            if (dp[i][0] > longestLen) {
                longestLen = dp[i][0];
            }
        }
        int res = 0;
        for (int i = 0; i < dp.length; i++) {
            if (dp[i][0] == longestLen) res += dp[i][1];
        }
        return res;
    }
}
