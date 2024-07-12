class Solution {
    public long maximumTotalCost(int[] nums) {
        long[] dp_pos = new long[nums.length]; // dp must end with nums i && nums i must end with '+'
        long[] dp_neg = new long[nums.length]; // dp must end with nums i && nums i must end with '-'
        dp_pos[0] = nums[0];
        dp_neg[0] = Long.MIN_VALUE;
        for (int i = 1; i < nums.length; i++) {
            dp_pos[i] = Math.max(dp_pos[i - 1], dp_neg[i - 1]) + nums[i]; // nums i be one subarry or not
            dp_neg[i] = dp_pos[i - 1] - nums[i]; // nums i can not be one subarry under '-' case
        }
        return Math.max(dp_pos[nums.length - 1], dp_neg[nums.length - 1]);
    }
}