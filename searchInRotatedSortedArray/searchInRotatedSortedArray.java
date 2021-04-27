class Solution {
    public int search(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] > nums[right]) { // mid in left part
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid;
                } else {
                    left = mid;
                } 
            } else { // mid in right part
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
        }
        if (nums[left] == target) return left;
        else if (nums[right] == target) return right;
        else return -1;
    }
}
