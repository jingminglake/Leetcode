class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        int[] dp = new int[nums.length];
        Arrays.sort(nums);
        int[] prev = new int[nums.length];
        int longestLen = 1;
        int longestIndex = 0;
        for (int i = 0; i < dp.length; i++) {
            dp[i] = 1;
            prev[i] = -1; // defalut not prev
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                    if (dp[i] > longestLen) {
                        longestLen = dp[i];
                        longestIndex = i;
                    }
                }
            }
        }
        List<Integer> res = new ArrayList<>();
        int index = longestIndex;
        while (index != -1) {
            res.add(nums[index]);
            index = prev[index];
        }
        return res;
    }
}
