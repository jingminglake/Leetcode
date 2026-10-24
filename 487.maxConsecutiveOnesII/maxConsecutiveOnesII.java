class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int left = 0, right = 0;
        int zeros = 0;
        int res = 0;
        while (right < nums.length) {
            if (nums[right] == 0) {
                zeros++;
            }
            // make window valid
            while (zeros > 1) {
                if (nums[left] == 0) zeros--;
                left++;
            }
            res = Math.max(res, right - left + 1);
            right++;
        }
        return res;
    }
}