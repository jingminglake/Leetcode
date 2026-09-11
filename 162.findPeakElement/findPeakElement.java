class Solution {
    public int findPeakElement(int[] nums) {
        int len = nums.length;
        if (len == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[len - 1] > nums[len - 2]) return len - 1;
        int left = 1, right = nums.length - 2;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid] > nums[mid - 1]) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if (nums[left] < nums[right]) return right;
        else return left;
    }
}
