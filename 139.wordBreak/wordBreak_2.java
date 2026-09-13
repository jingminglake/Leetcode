class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        boolean[] dp = new boolean[s.length() + 1];
        dp[0] = true;

        for (int i = 1; i < dp.length; i++) {
            for (String word : wordDict) {
                int len = word.length();
                int j = i - len;
                
                if (j < 0 || !dp[j]) continue;

                String subS = s.substring(j, i);
                if (word.equals(subS)) {
                    dp[i] = true; 
                    break;
                }
            }
        }
        return dp[s.length()];
    }
}