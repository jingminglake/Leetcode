class Solution {
    public int findMin(int[] nums) {
        int left = 0, right = nums.length - 1;
        if (right == 0) return nums[0];
        if (nums[left] <= nums[right]) return nums[left];
        
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= nums[0]) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if (nums[left] <= nums[right]) return nums[left];
        else return nums[right];
    }
}
