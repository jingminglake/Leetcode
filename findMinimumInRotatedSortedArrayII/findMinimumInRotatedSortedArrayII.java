class Solution {
    public int findMin(int[] nums) {
        int left = 0, right = nums.length - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) { // mid must be in left part
                left = mid;
            } else if (nums[mid] < nums[right]) { // mid must be in right part
                right = mid;
            } else {
                right--; // not matter mid in left or right(we don't know), min should be in the left side of mid
            }
        }
        if (nums[left] < nums[right]) return nums[left];
        else return nums[right];
    }
}
