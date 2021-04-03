class Solution {
    public int splitArray(int[] nums, int m) {
        if (nums.length == 1) return nums[0];
        long left = nums[0], right = 0;
        for (int n : nums) {
            if (n > left) left = n;
            right += n;
        }
        while (left + 1 < right) {
            long mid = left + (right - left) / 2;
            if (lessEqualM(nums, m, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (lessEqualM(nums, m, left)) return (int)left;
        else if (lessEqualM(nums, m, right)) return (int)right;
        else return -1;
    }
    
    public boolean lessEqualM(int[] nums, int m, long mid) {
        int n = 0;
        int cur = 0;
        for (int i = 0; i < nums.length; i++) {
            cur += nums[i];
            if (i == nums.length - 1 || cur + nums[i + 1] > mid) {
                cur = 0;
                if (++n > m) return false; 
            }
        }
        return true;
    }
}
