class Solution {
    public int maxTotalReward(int[] rewardValues) {
        Arrays.sort(rewardValues);
        int res = 0;
        boolean[] dp = new boolean[2000 * 2000 + 1];
        dp[rewardValues[0]] = true;
        res = rewardValues[0];
        for (int k = 1; k < rewardValues.length; k++) {
            for (int i = 0; i < rewardValues[k]; i++) {
                dp[rewardValues[k]] = true;
                res = Math.max(res, rewardValues[k]);
                if (dp[i]) {
                    dp[rewardValues[k] + i] = true;
                    res = Math.max(res, rewardValues[k] + i);
                }
            }
        }
        return res;
    }
}