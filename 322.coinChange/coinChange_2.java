import java.util.Arrays;

class Solution {
    public int coinChange(int[] coins, int amount) {
        int impossible = amount + 1;

        int[] dp = new int[amount + 1];
        Arrays.fill(dp, impossible);

        dp[0] = 0;

        for (int currentAmount = 1; currentAmount <= amount; currentAmount++) {
            for (int coin : coins) {
                if (coin <= currentAmount) {
                    dp[currentAmount] = Math.min(dp[currentAmount], dp[currentAmount - coin] + 1);
                }
            }
        }

        return dp[amount] == impossible ? -1 : dp[amount];
    }
}