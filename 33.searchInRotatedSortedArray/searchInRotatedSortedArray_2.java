class Solution {
    public int search(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[left]) { // mid is in left part
               if (target >= nums[left] && target < nums[mid]) { // target in the ascend range
                   right = mid - 1;
               } else {
                   left = mid + 1;
               }
            } else { // mid is in right part
                if (target > nums[mid] && target <= nums[right]) { // target in the ascend range
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
}