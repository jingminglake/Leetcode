class Solution {
    public int rob(int[] nums) {
        if (nums.length < 2) return nums[0];
        int[] g = new int[nums.length]; // must rob
        int[] h = new int[nums.length]; // must not rob
        g[0] = nums[0];
        h[0] = 0;
        for (int i = 1; i < nums.length; i++) {
            g[i] = nums[i] + h[i - 1];
            h[i] = Math.max(g[i - 1], h[i - 1]);
        }
        return Math.max(g[nums.length - 1], h[nums.length - 1]);
    }
}
