class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        if (s == null)
            return true;
        boolean[] dp = new boolean[s.length() + 1];
        dp[0] = true;
        Set<String> set = new HashSet<>(wordDict);
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j >= 0; j--) {
                if (dp[j] && set.contains(s.substring(j, i + 1))) {
                    dp[i + 1] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
}
