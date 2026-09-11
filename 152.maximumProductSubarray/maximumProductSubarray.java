class Solution {
    public int maxProduct(int[] nums) {
        int res = nums[0];
        int[] g = new int[nums.length]; // max prod
        int[] h = new int[nums.length]; // min prod
        g[0] = h[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            int c1 = g[i - 1] * nums[i];
            int c2 = h[i - 1] * nums[i];
            g[i] = Math.max(Math.max(c1, c2), nums[i]);
            h[i] = Math.min(Math.min(c1, c2), nums[i]);
            res = Math.max(res, g[i]);
        }
        return res;
    }
}
