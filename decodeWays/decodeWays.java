class Solution {
    public int numDecodings(String s) {
        int[] dp = new int[s.length()];
        if (s.charAt(0) - '0' != 0) {
            dp[0] = 1;
        } else {
            dp[0] = 0;
        }
        if (s.length() == 1) return dp[0];
        dp[1] = 0;
        if (s.charAt(1) != '0') dp[1] += dp[0];
        int num = Integer.valueOf(s.substring(0, 2));
        if (num >= 10 && num <= 26) {
            dp[1]++;
        }
        for (int i = 2; i < s.length(); i++) {
            int num1 = Integer.valueOf(s.substring(i, i + 1));
            if (num1 != 0) dp[i] += dp[i - 1];
            
            int num2 = Integer.valueOf(s.substring(i - 1, i + 1));
            if (num2 >= 10 && num2 <= 26) dp[i] += dp[i - 2];
        }
        return dp[s.length() - 1];
    }
}
