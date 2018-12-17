class Solution {
    public void moveZeroes(int[] nums) {
        if (nums == null || nums.length == 0)
            return;
        int left = 0, right = 0;
        while (right < nums.length) {
            if (nums[right] != 0)
                nums[left++] = nums[right];
            right++;
        }
        while (left < nums.length)
            nums[left++] = 0;
    }
}
