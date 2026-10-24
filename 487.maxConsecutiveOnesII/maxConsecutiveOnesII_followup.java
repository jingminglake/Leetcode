class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int left = 0, right = 0;
        int lastZero = -1;
        int res = 0;
        while (right < nums.length) {
            if (nums[right] == 0) {
                left = lastZero + 1;
                lastZero = right;
            }
            res = Math.max(res, right - left + 1);
            right++;
        }
        return res;
    }
}