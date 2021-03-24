class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        if (n == 1 || nums[0] < nums[n - 1]) return nums[0];
        int left = 0, right = n - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[left] == nums[right]) {
                if (nums[mid] > nums[left]) {
                    left = mid;
                } else if (nums[mid] < nums[left]) {
                    right = mid;
                } else {
                   right--;
                }
            } else {
                if (nums[mid] >= nums[left]) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
        }
        if (nums[left] <= nums[right]) return nums[left];
        else return nums[right];
    }
}
