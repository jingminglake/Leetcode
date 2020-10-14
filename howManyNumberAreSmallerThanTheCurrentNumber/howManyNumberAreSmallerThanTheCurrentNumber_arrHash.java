class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] res = new int[nums.length];
        int[] count = new int[101];
        for (int n : nums) count[n]++;
        int[] smaller = new int[101];
        smaller[0] = 0;
        for (int i = 1; i < smaller.length; i++) {
            smaller[i] = smaller[i - 1] + count[i - 1];
        }
        for (int i = 0; i < res.length; i++) {
            res[i] = smaller[nums[i]];
        }
        return res;
    }
}
